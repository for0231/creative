<?php
function dynamic_form($form, &$form_state) {
  $form['room_type'] = array(
    '#type' => 'radios',
    '#options' => drupal_map_assoc(array(t('Study Room'), t('Small Conference Room'), t('Board Room'))),
    '#title' => t('What type of room do you require?'),
  );
  
  $form['study_room'] = array(
    '#type' => 'fieldset',
    '#title' => t('Study Room Details'),
    '#states' => array(
      'visible' => array(
        ':input[name="room_type"]' => array('value' => t('Study Room')),
      ),
    ),
  );
  $form['study_room']['equipment'] = array(
    '#type' => 'checkboxes',
    '#options' => drupal_map_assoc(array(t('Chairs'),t('PC'))),
    '#title' => t('What equipment do you need?'),
    '#states' => array(
      'visible' => array(
        ':input[name="room_type"]' => array('value' => t('Study Room')),
      ),
    ),
  );
  $form['study_room']['chairs'] = array(
    '#type' => 'textfield',
    '#title' => t('How many chairs do you need?:'),
    '#size' => 4,
    '#states' => array(
      'visible' => array(
        ':input[name="equipment[Chairs]"]' => array('checked' => TRUE),
      ),
    ),
  );
  $form['study_room']['pc'] = array(
    '#type' => 'textfield',
    '#title' => t('What Type of PC do you need?:'),
    '#size' => 15,
    '#states' => array(
      'visible' => array(
        ':input[name="equipment[PC]"]' => array(
          'checked' => TRUE,
        ),
      ),
    ),
  );


  $form['small_conference_room'] = array(
    '#type' => 'fieldset',
    '#title' => t('small_conference_room Information'),
    '#states' => array(
      'visible' => array(
        ':input[name="room_type"]' => array(
          'value' => t('Small Conference Room'),
        ),
      ),
    ),
  );
  $form['small_conference_room']['how_many_pcs'] = array(
    '#type' => 'select',
    '#title' => t('How many PCs do you need set up in the small conference room?'),
    '#options' => array(
      '1' => t('One'),
      '2' => t('Two'),
      '3' => t('Three'),
      '4' => t('Four'),
      '5' => t('Lots'),
    ),
  );
  $form['small_conferrence_room']['comment'] = array(
    '#type' => 'item',
    '#description' => t("Wow, that's a long time."),
    '#states' => array(
      'visible' => array(
        ':input[name="how_many_pcs"]' => array('value' => '5'),
      ),
    ),
  );
  $form['small_conference_room']['room_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Which room do you want to use?:'),
  );
  $form['small_conference_room']['hours'] = array(
    '#type' => 'select',
    '#options' => drupal_map_assoc(array(t('Free'), t('Paid'))),
    '#title' => t('Do you want to reserve the room when it is free (no fees) or paid (prime time)?'),
  );
  $form['small_conference_room']['hours_writein'] = array(
    '#type' => 'textfield',
    '#size' => 50,
    '#title' => t('Please enter the date and time you would like to reserve the room and the duration.'),
    '#states' => array(
      'visible' => array(
        ':input[name="hours"]' => array('value' => t('Free')),
        ':input[name="hours"]' => array('value' => t('Paid')),
      ),
    ),
  );
  $form['small_conferrence_room']['reminder'] = array(
    '#type' => 'item',
    '#description' => t('Remember to enter the date, start time, and end time.'),
    '#states' => array(
      'visible' => array(
        'input[name="hours"]' => array('value' => t('Free')),
        'input[name="hours"]' => array('value' => t('Paid')),
        'input[name="hours_writein"]' => array('value' => array('filled' => TRUE),),
      ),
    ),
  );

  $form['board_room'] = array(
    '#type' => 'fieldset',
    '#title' => t('Board Room Information'),
    '#states' => array(
      'visible' => array(
        ':input[name="room_type"]' => array('value' => t('Board Room')),
      ),
    ),
  );
  $form['board_room']['more_info'] = array(
    '#type' => 'textarea',
    '#title' => t('Please enter the date and time of when you would like to reserve the board room'),
  );
  $form['board_room']['info_provide'] = array(
    '#type' => 'checkbox',
    '#title' => t('Check here if you have provided information above'),
    '#disabled' => TRUE,
    '#states' => array(
      ':input[name="more_info"]' => array('filled' => TRUE),
    ),
  );
  $form['expand_more_info'] = array(
    '#type' => 'checkbox',
    '#title' => t('Check here if you want to add special instructions.'),
  );
  $form['more_info'] = array(
    '#type' => 'fieldset',
    '#title' => t('Special Instructions'),
    '#collapsible' => TRUE,
    '#states' => array(
      'expanded' => array(
        ':input[name="expand_more_info"]' => array('checked' => TRUE),
      ),
    ),
  );
  $form['more_info']['feedback'] = array(
    '#type' => 'textarea',
    '#title' => t('Please provide any additional details that will help us better serve you.'),
  );
  $form['deadline'] = array(
    '#title' => t('Deadline'),
    '#type'  => 'date',
    '#description' => t('Set the deadline'),
    '#default_value' => array(
      'month' => format_date(time(), 'custom', 'n'),
      'day'   => format_date(time(), 'custom', 'j'),
      'year'  => format_date(time(), 'custom', 'Y'),
    ),
  );
  $form['weight'] = array(
    '#type' => 'weight',
    '#title' => t('Weight'),
    '#default_value' => 0,
    '#delta' => 10,
    '#description' => t('In listings, the heavier vocabularies will sink and the linghter vocabularies will be positioned nearer the top.'),
  );
  $form['#attributes']['enctype'] = 'multipart/form-data';
  $form['picture']['picture_uploads'] = array(
    '#type' => 'file',
    '#title' => t('Upload picture'),
    '#size' => 48,
    '#description' => t('Your virtual face or picture'),
  );
  $form['my_button'] = array(
    '#type' => 'button',
   
    '#value' => 'foo2',
  );
  $form['my_image_button'] = array(
    '#type' => 'image_button',
    '#src ' => 'misc/powered-blue-80x15.png',
    '#value' => 'foo',
  );
  $form['disclaimer'] = array(
    '#prefix' => '<div style="color:#f00; width: 200px;float:left;">',
    '#markup' => t('The information below is entirely optional.'),
    '#suffix' => '</div>',
  );
  $form['removed'] = array(
    '#title' => t('Shoe size'),
    '#type' => 'item',
    '#description' => t('This question has been removed because the law prohibits us from asking your shoe size.'),
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit your information'),
  );
  return $form;
}

function dynamic_form_submit($form, &$form_state) {
  drupal_set_message(t('Submitting values: @values', array('@values' => var_export($form_state['values'], TRUE))));
}
function automobile_dependent_dropdown_submit($form, &$form_state) {
  drupal_set_message(t('Submitting values: @values', array('@values' => var_export($form_state['values'], TRUE))));
}
/**
 * A form with a dropdown whose options are dependent on a
 * choice made in a previous dropdown.
 *
 * On changing the first dropdown, the options in the second
 * are updated.
 */
function automobile_dependent_dropdown($form, &$form_state) {
  // get the list of manufacturers to populate the manufacturer dropdown
  $options_first = _automobile_get_manufacturer_dropdown_options();
  $selected = isset($form_state['values']['manufacturer_dropdown']) ? $form_state['values']['manufacturer_dropdown'] : key($options_first);
  $form['manufacturer_dropdown'] = array(
    '#type' => 'select',
    '#title' => 'Manufacturer',
    '#options' => $options_first,
    '#default_value' => $selected,
    '#ajax' => array(
      'callback' => 'automobile_dependent_dropdown_callback',
      'wrapper' => 'dropdown_model_replace',
    ),
  );
  $form['model_dropdown'] = array(
    '#type' => 'select',
    '#title' => 'Model',
    '#prefix' => '<div id="dropdown_model_replace">',
    '#suffix' => '</div>',
    '#options' => _automobile_get_model_dropdown_options($selected),
    '#default_value' => isset($form_state['values']['model_dropdown']) ? $form_state['values']['model_dropdown'] : '',
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
  );
  return $form;
}

function automobile_dependent_dropdown_callback($form, $form_state) {
  return $form['model_dropdown'];
}

function _automobile_get_manufacturer_dropdown_options() {
  return drupal_map_assoc(array(t('Honda'), t('Toyota'), t('Ford'), t('Volkswagen')));
}

function _automobile_get_model_dropdown_options($key = '') {
  $options = array(
    t('Honda') => drupal_map_assoc(array(t('Accord'), t('Civic'), t('CRX'), t('Pilot'))),
    t('Toyota') => drupal_map_assoc(array(t('Camry'), t('Yaris'), t('Tundra'),t('Tacoma'))),
    t('Ford') => drupal_map_assoc(array(t('F-150'), t('Explorer'), t('Escape'), t('Edge'))),
    t('Volkswagen') => drupal_map_assoc(array(t('GTI'), t('Passat'), t('Jeta'), t('Polo'))),
  );
  if (isset($options[$key])) {
    return $options[$key];
  }
  else {
    return array();
  }
}

/**
 * A form with test demo for net examples
 */
function more_test_form($form, &$form_state) {
  $form['city'] = array(
    '#type' => 'textfield',
    '#title' => 'City',
    '#maxlength' => 128,
    '#autocomplete_path' => 'cities/autocomplete',
  );



  $form['admin']['author'] = array(
    '#type' => 'textfield',
    '#title' => t('Authored by'),
    '#size' => 30,
    '#maxlength' => 60,
    '#autocomplete_path' => 'user/autocomplete',
    '#default_value' => '',
    '#weight' => -1,
  );


  // Access log settings:
  $options = array('1' => t('Enabled'), '0' => t('Disabled'));
  $form['access'] = array(
    '#type' => 'fieldset',
    '#title' => t('Access log settings'),
    '#tree' => TRUE,
  );
  $form['access']['log'] = array(
    '#type' => 'radios',
    '#title' => t('Log'),
    '#default_value' =>  variable_get('log', 0),
    '#options' => $options,
    '#description' => t('The log.'),
  );
  $period = drupal_map_assoc(array(3600, 10800, 21600, 32400, 43200, 86400, 172800, 259200, 604800, 1209600, 2419200, 4838400, 9676800), 'format_interval');
  $form['access']['timer'] = array(
    '#type' => 'select',
    '#title' => t('Discard logs older than'),
    '#default_value' => variable_get('timer', 259200),
    '#options' => $period,
    '#description' => t('The timer.'),
  );
  // Description
  $form['details'] = array(
    '#type' => 'fieldset',
    '#title' => t('Details'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['details']['description'] = array(
    '#type' => 'textarea',
    '#title' => t('Describe it'),
    '#default_value' =>  variable_get('description', ''),
    '#cols' => 60,
    '#rows' => 5,
    '#description' => t('Log description.'),
  );
  $form['details']['admin'] = array(
    '#type' => 'checkbox',
    '#title' => t('Only admin can view'),
    '#default_value' => variable_get('admin', 0),
  );
  $form['name'] = array(
    '#type' => 'textfield',
    '#title' => t('Name'),
    '#size' => 30,
    '#maxlength' => 64,
    '#description' => t('Enter the name for this group of settings'),
  );
  $form['div_tag'] = array(
  '#type' => 'markup',
  '#value' => '<div class="foo">',
);
  $form['sample_textfield'] = array(
  '#size' => '20', // the visual width of the text box
  '#weight' => '0', // Higher numbers will sink this field to the bottom of the form, lower numbers will float it to the top
  '#field_prefix' => '<div class=\'sample_class\'>', // Code that will appear before the input field
  '#field_suffix' => '</div>', // Code that will appear after the input field
  '#type' => 'textfield', // The field type
  '#title' => t('Sample textfield'), // Title label
  '#default_value' => 'a sample value', // The text that will appear in the box by default
);
  $form['hidden'] = array('#type' => 'value', '#value' => 'is_it_here');
  $form['submit'] = array('#type' => 'submit', '#value' => t('Save')); 
  return $form;
}

