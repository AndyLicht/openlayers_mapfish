var mapfishControl = function(opt_options) 
{
    var options = opt_options || {};
    var button = document.createElement('button');
    button.type = 'button';
    button.innerHTML = 'Mapfish';
    button.id = 'mapfish';

    var this_ = this;
    var element = document.createElement('div');
    element.className = 'mapfish-button ol-unselectable ol-control';
    element.appendChild(button);

    ol.control.Control.call(this, {
	element: element,
	target: options.target
    });
};
ol.inherits(mapfishControl, ol.control.Control);

(function ($)
{
    Drupal.behaviors.mapfish =
    {
        attach: function (context, settings)
        {
            jQuery(window).load(function () 
            {
                $('#mapfish').click(function()
                {
                    var id = $('.openlayers-map').attr('id');
                    var mapOL = Drupal.openlayers.getMapById(id).map;
                    var json = new Object();
                    var map = new Object();
                    map.rotation = 0;
                    map.projection = mapOL.getView().getProjection().lb;

                    map.dpi = 72;
                    json.layout = "A4 landscape";
                    json.attributes = new Object();
                    json.attributes.map = map;
                    map.layers = new Array;
                    map.center = mapOL.getView().getCenter();
                    map.scale = getcurrentScale(mapOL.getView().getResolution(),mapOL.getView().getProjection().getUnits());
                    
                    layerReverse = mapOL.getLayers();
                    layerReverse.forEach(function( layer ) 
                    {
                        if(layer.getVisible() && layer.getProperties().name !== 'layer_measure' )
                        {
                            var layer_ = new Object();
                            layer_.baseURL = layer.getSource().getUrls()[0];
                            layer_.imageFormat = "image/png";
                            layer_.type = layer.get('print_type');
                            layer_.opacity = 1;
                            layer_.layers = new Array;
                            layer_.layers.push(layer.get('print_layer'));
                            map.layers.push(layer_);
                        }
                    });
                    map.layers = map.layers.reverse();
                    console.log(JSON.stringify(json));

                    $('#mapfish').html('waiting');
                    $('#mapfish').prop("disabled",true);
                    $.ajax(
                    {
                        method:'POST',
                        url: window.location.protocol + "//" + window.location.host + "/geoportal3/admin/structure/mapfish/request",
                        data: {mapdata:json}
                    })
                    .done(function( data ) 
                    {
                        console.log(data);
                        window.location.href = (data);
                        $('#mapfish').html('mapfish');
                        $('#mapfish').prop("disabled",false);
                    })
                    .fail(function( error )
                    {
                        console.log("FAIL");
                        console.log(error);
                        $('#mapfish').html('mapfish');
                        $('#mapfish').prop("disabled",false);
                    });
                });
            });
        }
    }
})(jQuery);

function getcurrentScale(resolution, units)
{
    var dpi = 25.4 / 0.28;
    var mpu = ol.proj.METERS_PER_UNIT[units];
    var scale = resolution*mpu*39.37 * dpi;
    return scale;
}