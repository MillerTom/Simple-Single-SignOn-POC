<?php
/**
 * Simple SSO Settings
 *
 * @param $form
 * @param $form_state
 * @return mixed
 */
function simple_sso_settings($form, &$form_state)
{
  $form['simple_sso_key'] = array(
    '#type' => 'textfield',
    '#title' => t('Simple SSO API Key'),
    '#description' => t('Enter an API Key'),
    '#default_value' => variable_get('simple_sso_key', ''),
  );

  $form['simple_sso_allowed_domains'] = array(
    '#type' => 'textarea',
    '#title' => t('Allowed Domains'),
    '#description' => t('List of authorized domains. Use comma separated values i.e domain1.com, domain2.com, domain3.com'),
    '#default_value' => variable_get('simple_sso_allowed_domains', ''),
  );

  return(system_settings_form($form));
}
