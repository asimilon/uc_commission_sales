<?php
/**
 * @file
 * Administration page callbacks for uc_commission_sales module.
 */

/**
 * Form builder.  Configure uc_commission_sales module.
 *
 * @ingroup forms
 * @see system_settings_form().
 */
function uc_commission_sales_settings() {
  $form['uc_commission_sales_rate'] = array(
    '#type' => 'textfield',
    '#title' => t('Commission percentage rate'),
    '#default_value' => variable_get('uc_commission_sales_rate', 0),
    '#size' => 30,
    '#maxlength' => 3,
    '#description' => t('The percentage commission to be deducted from each sale.'),
    '#required' => TRUE
  );
  $form['uc_commission_sales_masspay_day'] = array(
    '#type' => 'textfield',
    '#title' => t('Day of the month to settle'),
    '#default_value' => variable_get('uc_commission_sales_masspay_day', 1),
    '#size' => 30,
    '#maxlength' => 2,
    '#description' => t('Which day of the month to mass pay content creators.'),
    '#required' => TRUE
  );
  $form['uc_commission_sales_paypal_server'] = array(
    '#type' => 'radios',
    '#title' => t('Sandbox or Live PayPal server'),
    '#default_value' => variable_get('uc_commission_sales_paypal_server', 'sandbox'),
    '#description' => t('Which server to use when mass paying.'),
    '#options' => array('sandbox' => t('Sandbox'), 'live' => t('Live Server')),
  );
  $form['uc_commission_sales_paypal_api_username'] = array(
    '#type' => 'textfield',
    '#title' => t('API username'),
    '#default_value' => variable_get('uc_commission_sales_paypal_api_username', ''),
    '#size' => 90,
    '#description' => t('Your PayPal API username.'),
    '#required' => TRUE
  );
  $form['uc_commission_sales_paypal_api_password'] =  array(
    '#type' => 'textfield',
    '#title' => t('API password'),
    '#default_value' => variable_get('uc_commission_sales_paypal_api_password', ''),
    '#size' => 90,
    '#description' => t('Your PayPal API password'),
    '#required' => TRUE
  );
  $form['uc_commission_sales_paypal_api_signature'] =  array(
    '#type' => 'textfield',
    '#title' => t('API signature'),
    '#default_value' => variable_get('uc_commission_sales_paypal_api_signature', ''),
    '#size' => 90,
    '#description' => t('The provided API signature.'),
    '#required' => TRUE
  );

  $form['#submit'][] = 'uc_commission_sales_settings_submit';

  return system_settings_form($form);
}

/**
 * Validate uc_commission_sales settings.
 */
function uc_commission_sales_settings_validate($form, &$form_state) {
  $rate = $form_state['values']['uc_commission_sales_rate'];
  if (!is_numeric($rate)) {
    form_set_error('uc_commission_sales_rate', t('Please enter a number'));
  }
  if (($rate < 0) || ($rate > 99)) {
    form_set_error('uc_commission_sales_rate', t('Please enter a number between 0 and 99'));
  }
  $masspay_day = $form_state['values']['uc_commission_sales_masspay_day'];
  if (!is_numeric($masspay_day)) {
    form_set_error('uc_commission_sales_masspay_day', t('Please enter a number'));
  }
  if (($masspay_day < 1) || ($masspay_day > 28)) {
    form_set_error('uc_commission_sales_masspay_day', t('Please enter a day number between 1 and 28'));
  }
}

/**
 * Process uc_commission_sales settings form.
 */
function uc_commission_sales_settings_submit($form, $form_state) {
  variable_set('uc_commission_sales_rate', $form_state['values']['uc_commission_sales_rate']);
  variable_set('uc_commission_sales_masspay_day', $form_state['values']['uc_commission_sales_masspay_day']);
  variable_set('uc_commission_sales_paypal_server', $form_state['values']['uc_commission_sales_paypal_server']);
  variable_set('uc_commission_sales_paypal_api_username', $form_state['values']['uc_commission_sales_paypal_api_username']);
  variable_set('uc_commission_sales_paypal_api_password', $form_state['values']['uc_commission_sales_paypal_api_password']);
  variable_set('uc_commission_sales_paypal_api_signature', $form_state['values']['uc_commission_sales_paypal_api_signature']);
}
