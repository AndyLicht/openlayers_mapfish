<?php
/**
 * @file
 * Default sources
 */

/**
 * Implements hook_default_sources()
 */
function openlayers_mapfish_default_openlayers_sources() {
    $export = array(); 
    
    $ol_source = new stdClass();
    $ol_source->disabled = FALSE; /* Edit this to true to make a default source disabled initially */
    $ol_source->api_version = 1;
    $ol_source->machine_name = 'openlayers_source_bkg_osm';
    $ol_source->name = 'BKG OpenStreetMap';
    $ol_source->description = 'OpenStreetMap gehostet vom BKG';
    $ol_source->factory_service = 'openlayers.Source:TileWMS';
    $ol_source->options = array(
        'url' => 'http://mapserver.testbed.gdi-de.org/maps/osm_direct/service?',
        'wms_layers' => 'osm',
        'version' => '',
        'params' => array(
            'LAYERS' => 'osm',
        ),
    );
    $export['openlayers_source_bkg_osm'] = $ol_source;
    
    
    
    return $export;
}
