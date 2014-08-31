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
}

/**
 * Process uc_commission_sales settings form.
 */

function uc_commission_sales_settings_submit($form, $form_state) {
  variable_set('uc_commission_sales_rate', $form_state['values']['uc_commission_sales_rate']);
}
