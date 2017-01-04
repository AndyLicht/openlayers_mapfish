<?php

/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

function openlayers_mapfish_install_variables()
{
    variable_set('openlayers_mapfish_serverurl','http://url.com/api');
}
function openlayers_mapfish_uninstall_variables()
{   
    variable_del('openlayers_mapfish_serverurl');
}