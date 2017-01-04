Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Control:Mapfish',
  init: function(data) {
    return new mapfishControl(data.opt);
  }
});


