<?php

/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

function openlayers_mapfish_configure()
{
    $form = array();
    $form['introduction'] = array(
        '#title' => t('OpenLayers 3 MapFish Konfiguration'),
        '#type' => 'fieldset',
        '#collapsible' => false,
        '#collapsed' => false,        
    );
    $form['introduction']['text'] = array(
        '#type' => 'markup',
        '#markup' => t('Bitte setzen Sie hier Ihre Parameter für die MapFish Anbindung.<p>'),
    );
    $form['introduction']['openlayers_mapfish_serverurl'] = array(
        '#type' => 'textfield',
        '#title' => t('URL zum MapFish Endpunkt'),
        '#default_value' => variable_get('openlayers_mapfish_serverurl'),
        '#size' => 100,
        '#maxlength' => 100, 
        '#required' => FALSE,
    );
    return system_settings_form($form);
}