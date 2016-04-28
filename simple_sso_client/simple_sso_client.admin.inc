<?php
/**
 * Simple SSO Client Settings
 *
 * @param $form
 * @param $form_state
 * @return mixed
 */
function simple_sso_client_settings($form, &$form_state)
{
  $form['simple_sso_client_key'] = array(
    '#type' => 'textfield',
    '#title' => t('Simple SSO Server API Key'),
    '#description' => t('API Key set on the server'),
    '#default_value' => variable_get('simple_sso_client_key', ''),
  );

  $form['simple_sso_client_server_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Simple SSO Server Domain'),
    '#description' => t('Domain for the SSO server i.e http://sso.example.com'),
    '#default_value' => variable_get('simple_sso_client_server_url', ''),
  );

  $form['simple_sso_client_server_token'] = array(
    '#type' => 'textfield',
    '#title' => t('Simple SSO Client Token'),
    '#description' => t('Token generated from Simple SSO Server'),
    '#default_value' => variable_get('simple_sso_client_server_token', ''),
    '#disabled' => true
  );

  $form['simple_sso_client_submit'] = array(
    '#type' => 'submit',
    '#description' => 'Generate a token from the server',
    '#value' => 'Generate Token',
  );

  $form['simple_sso_client_submit_save'] = array(
    '#type' => 'submit',
    '#value' => 'Submit',
  );

  $form['#submit'] = array('simple_sso_client_settings_submit');
  return($form);
}

/**
 * Submission form for SSO client settings
 *
 * @param $form
 * @param $form_state
 */
function simple_sso_client_settings_submit(&$form, &$form_state)
{
  $key = $form_state['values']['simple_sso_client_key'];
  $url = $form_state['values']['simple_sso_client_server_url'];
  $host = $_SERVER['HTTP_HOST'];

  if($form_state['clicked_button']['#value'] == 'Generate Token'){
    $contents = file_get_contents($url . '/simple-sso/token/' . $key . '?domain=' . $host);

    if($contents){
      $contents_json = json_decode($contents, true);
      if($contents_json['status'] == 'status'){
        $token = $contents_json['token'];
      }

      drupal_set_message($contents_json['message'], $contents_json['status']);
    }
  }

  if(isset($token)){
    variable_set('simple_sso_client_server_token', $token);
  }

  variable_set('simple_sso_client_key', $key);
  variable_set('simple_sso_client_server_url', $url);
}
