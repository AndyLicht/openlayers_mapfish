<?php

/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

function openlayers_mapfish_request()
{ 
    $url = variable_get('openlayers_mapfish_serverurl')."/print/geoportal/report.pdf";
    $options['method'] = 'POST';
    
    $options['data'] = json_encode($_POST['mapdata']);
    $options['headers']['Content-Type'] = 'application/json';
    
    $response = drupal_http_request($url, $options);
    if($response->code != 200)
    {
        http_response_code(500);
    }
    else
    {
        $json = json_decode($response->data);
        $downloaded = false;
        $optionsStatus['method'] = 'GET';
        while (!$downloaded)
        {
            sleep(3);
            $urlStatus = variable_get('openlayers_mapfish_serverurl').$json->statusURL;
            $response = drupal_http_request($urlStatus, $optionsStatus);
            $jsonStatus = json_decode($response->data);
            $status = $jsonStatus->status;
            $downloaded = $jsonStatus->done;
        }
        if($status === 'finished')
        {    
            $urlDownload = variable_get('openlayers_mapfish_serverurl').$json->downloadURL;
            echo $urlDownload;
            http_response_code(200);
        }
        else
        {
            http_response_code(500);
        }
    }
}