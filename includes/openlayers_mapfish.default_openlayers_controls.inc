<?php
/**
 * @file
 * Provide default controls.
 */

/**
 * Implements hook_default_controls().
 */
function openlayers_mapfish_default_openlayers_controls() 
{
    $export = array();
   
    $ol_control = new stdClass();
    $ol_control->api_version = 1;
    $ol_control->machine_name = 'openlayers_control_mapfish';
    $ol_control->name = 'Mapfish';
    $ol_control->description = 'Control to export the map as pdf';
    $ol_control->factory_service = 'openlayers.Control:Mapfish';
    $ol_control->options = array();
    $export['openlayers_control_mapfish'] = $ol_control;
    
    return $export;
}