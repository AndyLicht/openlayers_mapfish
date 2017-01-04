<?php
/**
 * @file
 * Default layers
 */

/**
 * Implements hook_default_layers()
 */
function openlayers_mapfish_default_openlayers_layers() {
    $export = array();
    $ol_layer = new stdClass();
    $ol_layer->disabled = FALSE; /* Edit this to true to make a default ol_layer disabled initially */
    $ol_layer->api_version = 1;
    $ol_layer->machine_name = 'openlayers_layer_mapfish_bkg_osm';
    $ol_layer->name = 'BKG: OSM';
    $ol_layer->description = '';
    $ol_layer->factory_service = 'openlayers.Layer:Tile';
    $ol_layer->options = array(
        'source' => 'openlayers_source_bkg_osm',
        'visible' => 1,
        'opacity' => 1,
        'base' => true,
        'tree_uid' => '1',
        'tree_group' => 'Basislayer',
        'tree_title' => 'BKG OSM',
        'tree_name' => 'openlayers_layer_mapfish_bkg_osm',
        'tree_extent' => '',
        'print_type' => 'wms',
        'print_layer' => 'osm'  
    );
    $export['openlayers_layer_mapfish_bkg_osm'] = $ol_layer;
    
    // 
    $ol_layer = new stdClass();
    $ol_layer->disabled = FALSE; /* Edit this to true to make a default ol_layer disabled initially */
    $ol_layer->api_version = 1;
    $ol_layer->machine_name = 'openlayers_layer_mapfish_bkg_webatlas_color';
    $ol_layer->name = 'BKG: Webatlas(Farbe)';
    $ol_layer->description = '';
    $ol_layer->factory_service = 'openlayers.Layer:Tile';
    $ol_layer->options = array(
        'source' => 'openlayers_source_bkg_webatlas_color',
        'visible' => 0,
        'opacity' => 1,
        'base' => true,
        'tree_uid' => '1',
        'tree_group' => 'Basislayer',
        'tree_title' => 'WebAtlas',
        'tree_name' => 'openlayers_layer_mapfish_bkg_webatlas_color',
        'tree_extent' => '',
        'print_type' => 'wms',
        'print_layer' => 'webatlasde'
    );
    $export['openlayers_layer_mapfish_bkg_webatlas_color'] = $ol_layer;
    
   
    $ol_layer = new stdClass();
    $ol_layer->disabled = FALSE; /* Edit this to true to make a default ol_layer disabled initially */
    $ol_layer->api_version = 1;
    $ol_layer->machine_name = 'openlayers_layer_mapfish_bkg_dop20';
    $ol_layer->name = 'BKG: DOP20';
    $ol_layer->description = '';
    $ol_layer->factory_service = 'openlayers.Layer:Tile';
    $ol_layer->options = array(
        'source' => 'openlayers_source_bkg_dop20',
        'visible' => 0,
        'opacity' => 1,
        'base' => true,
        'tree_uid' => '3',
        'tree_group' => 'Basislayer',
        'tree_title' => 'DOP20',
        'tree_name' => 'openlayers_layer_mapfish_bkg_dop20',
        'tree_extent' => '',
        'print_type' => 'wms',
        'print_layer' => 'rgb'
    );
    $export['openlayers_layer_mapfish_bkg_dop20'] = $ol_layer;
      
    $ol_layer = new stdClass();
    $ol_layer->api_version = 1;
    $ol_layer->machine_name = 'openlayers_layer_mapfish_tile_mapquest_osm';
    $ol_layer->name = 'MapQuest OpenStreetMap';
    $ol_layer->description = 'Layer MapQuest OpenStreetMap description';
    $ol_layer->factory_service = 'openlayers.Layer:Tile';
    $ol_layer->options = array(
        'source' => 'openlayers_source_mapquest_osm',
        'visible' => 0,
        'opacity' => 1,
        'base' => true,
        'tree_uid' => '3',
        'tree_group' => 'Mapnik OSM',
        'tree_title' => 'MapnkOSM',
        'tree_name' => 'openlayers_layer_mapfish_tile_mapquest_osm',
        'tree_extent' => '',
        'print_type' => 'wms',
        'print_layer' => 'rgb'
    );
    $export['openlayers_layer_mapfish_tile_mapquest_osm'] = $ol_layer;
    
    return $export;
}
