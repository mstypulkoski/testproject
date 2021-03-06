<?php

include_once('oa_portal.fields.inc');

/**
 * Form callback for Application form
 */
function oa_portal_p1_application_form($form_state) {
  $form = array();
  $form['#description'] = 'If you are ready to begin working.....';
  
  // Contact Information
  $form['contact'] = fieldset('Contact Information');
  $form['contact']['emerg1_name'] = textfield('Name', array('#prefix' => 'Emergency Contact 1'));
  $form['contact']['emerg1_phone'] = textfield('Phone');
  $form['contact']['emerg2_name'] = textfield('Name', array('#prefix' => 'Emergency Contact 2'));
  $form['contact']['emerg2_phone'] = textfield('Phone');

  // Education
  $form['education'] = fieldset('Education', 'Please do not note the year high school diploma was received');

  $edu_fields = array();
  $edu_fields['school'] = textfield('School', array('#options' => array('opt1' => 'Opt 1')));
  $edu_fields['grad_status'] = radios('Did you graduate', array(1 => 'Yes', 0 => 'No'));
  $edu_fields['degree'] = select('Degree Earned', array('Associates'));
  $edu_fields['city'] = textfield('City');
  $edu_fields['state'] = state();
  $edu_fields['year'] = textfield('Year');
  $edu_fields['major'] = textfield('Major');
  $edu_fields['minor'] = textfield('Minor');
  $edu_fields['coursework1'] = textfield('Relevant Course Work');
  $edu_fields['coursework2'] = textfield('');

  // @TODO Enable multiple entry
  $form['education']['edu'][] = $edu_fields;
  $form['education']['edu'][] = $edu_fields;
  
  // Experience
  $form['experience'] = fieldset('Experience');

  $form['experience']['recent_grad'] = checkbox('Check box if you are a recent college graduate');  
  $exp_fields['employer'] = textfield('Employer');
  $exp_fields['city'] = textfield('City');
  $exp_fields['state'] = state('State');
  $exp_fields['start_date'] = date_popup('Start Date');
  $exp_fields['end_date'] = date_popup('End Date');
  $exp_fields['present'] = checkbox('Present');
  $exp_fields['title'] = textfield('Title');
  $exp_fields['salary'] = textfield('Salary');
  $exp_fields['salary_period'] = radios('Salary', array('annual' => t('Annual'), 'hourly' => t('Hourly')));
  $exp_fields['description'] = textarea('Description', 5);
  $exp_fields['supervisor'] = textfield('Immediate Supervisor');
  $exp_fields['may_contact'] = checkboxes_yesno('May we contact?');
  $exp_fields['reason'] = textfield('Reason for leaving');
  $form['experience']['exp'][] = $exp_fields;
  
  
  // Preferences
  $form['preferences'] = fieldset('Preferences');
  $form['preferences']['distance'] = textfield('How far are you willing to commute on a daily basis?', 3, array(
    '#field_suffix' => t('Miles'),
  ));
  
  $form['preferences']['type'] = checkboxes('Check preferred employment type', array('Contract', 'Contract-to-hire', 'Direct Hire'), TRUE);
  $form['preferences']['work_days'] = checkboxes('Check the days you are willing to work', array('Any', 'M', 'T', 'W', 'Th', 'F', 'S', 'Su'), TRUE);
  $form['preferences']['shifts'] = checkboxes('Check the shifts you are willing to work', array('Any', 'Days', 'Nights', 'Evenings', 'Weekends'), TRUE);
  $form['preferences']['ptft'] = checkboxes('Would you prefer to work', array('Either', 'Part-time', 'Full-time'));
  $form['preferences']['legal_right'] = checkboxes_yesno('Can you, after employment, submit verification of your legal right to work in the U.S.?');
  $form['preferences']['felony'] = checkboxes_yesno('Have you been convicted of a felony within the last seven years?');
  $form['preferences']['felony']['#suffix'] = t('(An affirmative response to this question will not necessarily disqualify you from employment)<br \>MA residents should not answer this question');
  $form['preferences']['drug_alcohol_screen'] = checkboxes_yesno('As a condition of employment, you may be required to take and pass a drug and/or alcohol screen. Testing will be done at the company\'s expense and administered by a testing facility designated by the company. Results of any testing will be kept strictly confidential. If requested, are you willing to take the drug and/or alcohol screen?');
  $form['preferences']['referral'] = select('How did you hear about On Assignment Healthcare Staffing?',
    array('onassignment.com', 'other'));
  
  
  $form['preferences']['experience'] = textfield('Total years of experience');
  
  // Licensures & Certifications
  $form['licecerts'] = fieldset('Licensures/Certifications');

  $lc_fields['name'] = textfield('Licensure/Certification');
  $lc_fields['state'] = state();
  $lc_fields['number'] = textfield('License Number', 12);
  $lc_fields['expiry_date'] = date_popup('Expires');

  $form['licecerts']['lc'][] = $lc_fields;
  
  
  $form['proforgs'] = fieldset('Professional Organizations');
  $proforgs['none'] = checkbox('I am not a member of any organizations');
  $proforgs['org_name'] = textfield('Organization');
  $proforgs['org_role'] = textfield('Role');
  $proforgs['org_start'] = date_popup('From');
  $proforgs['org_end'] = date_popup('To');
  $form['proforgs']['orgs'][] = $proforgs;

  $terms_desc = '<p>I certify that the information provided on this Application is accurate. I understand 
  that the withholding of information or the giving of false information on this Application may 
  result in a refusal to hire or disciplinary action including, but not limited to, termination. 
  I understand and agree that if I am offered employment by the company, it will be on an at-will basis. 
  This means that either the Company or I may terminate the employment relationship at any time, 
  for any reason, with or without cause or notice. I also understand and agree that only an officer 
  of the Company can enter into an agreement on any other terms and he/she can only do so in writing 
  signed by the officer and me. I have read the above before signing this Application.</p>
  <p>I further understand and waive my right of privacy in this investigation and release and hold 
  harmless On Assignment from any liability</p>
  <p>I agree that any decision to hire me is contingent upon the results of my report, and certify that all
  statements and answers on my Application, resume, or interview are true and complete to the best of my
  knowledge. I understand that if any statements are false or that if information has been omitted, this will
  be cause for disqualification and immediate termination of my employment. I further authorize 
  On Assignment to check my conviction record as needed, on a continuous basis as it relates to my employment.</p>
  <p>I authorize On Assignment to release any employment records, including health records submitted 
  to On Assignment to any customer of On Assignment for consideration of employment at customer facility.</p>';
  
  $form['terms'] = terms($terms_desc);

  oa_portal_submit($form);
  return $form;
}

/**
 * Form validation callback for Application
 */
/*
function oa_portal_p1_application_form_validate($form, &$form_state) {
}
*/

/**
 * Form submission callback for Application
 */
/*
function oa_portal_p1_application_form_submit($form, &$form_state) {
}
*/

function oa_portal_p1_contact_form() {
  $form['contact'] = fieldset('Contact Information');
  $form['contact']['first_name'] = textfield('First Name');
  $form['contact']['middle'] = textfield('Middle Initial');
  $form['contact']['last_name'] = textfield('Last Name');
  $form['contact']['middle']['#required'] = FALSE;
  $form['contact']['address'] = address();
  $form['contact']['primary_phone'] = textfield('Primary Phone');
  $form['contact']['mobile_phone'] = textfield('Cell Phone');
  $form['contact']['email'] = textfield('Email');
  oa_portal_submit($form);
  return $form;
}

/**
 * Form validation callback for Contact
 */
/*
function oa_portal_p1_contact_form_validate($form, &$form_state) {
}
*/

/**
 * Form submission callback for Background/Reference Check
 */
/*
function oa_portal_p1_contact_form_submit($form, &$form_state) {
}
*/

/**
 * Form callback for Background/Reference Check
 */
function oa_portal_p2_background_reference_form($form_state) {
  $form = array();
  $form['#description'] = t('');

  // 
  $form['consent'] = fieldset('Background Investigation Consent');
  $form['consent']['maiden_name'] = textfield('Maiden/other names used');
  $form['consent']['dob'] = date_popup('Date of birth');
  $form['consent']['sin'] = textfield_sin();
  $form['consent']['dl_number'] = textfield('Driver License Number');
  $form['consent']['dl_state'] = state('Driver License State');
  $form['consent']['residence_state'] = textfield('Lived at your current address since');
  $form['consent']['disclaimer'] = markup('Note: We need 7 years of address history. Please add all addresses for the past 7 years.');
  $form['consent']['certification'] = checkbox('I certify...');
  
  $form['reference1'] = fieldset('Reference Check 1');
  
  $ref = array();
  $ref['company'] = select('Company', array('Company A', 'Company B'));
  $ref['supervisor'] = textfield('Supervisor');
  $ref['address'] = address();
  $ref['phone'] = textfield('Phone');
  $ref['email'] = email();
  $ref['certification'] = checkbox('I hereby give permission to the above named employer to release information to On Assignment regarding my performance while employed at that facility');
  
  oa_portal_submit(&$form);
  return $form;
}

/**
 * Form validation callback for Background/Reference Check
 */
/*
function oa_portal_p2_background_reference_form_validate($form, &$form_state) {
}
*/

/**
 * Form submission callback for Background/Reference Check
 */
/*
function oa_portal_p2_background_reference_form($form, &$form_state) {
}
*/


/**
 * Form callback for Professional Organizations
 */
function oa_portal_p2_professional_orgs_form($form_state) {
  $form = array('#ajax' => array('enabled' => TRUE));

  $form['prof_orgs'] = fieldset('Professional Organizations');
  $form['prof_orgs']['no_orgs'] = checkbox('I am not a member of any organizations');
  $org['org_name'] = textfield('Organization');
  $org['org_role'] = textfield('Role');
  $org['org_date_from'] = date_popup('From');
  $org['org_date_to'] = date_popup('To');
  $form['prof_orgs']['org1']['#tree'] = TRUE;
  $form['prof_orgs']['org1'] = $org;
  $form['prof_orgs']['org2']['#tree'] = TRUE;
  $form['prof_orgs']['org2'] = $org;

  oa_portal_submit(&$form);
  return $form;
}

/**
 * Form validation callback for Professional Organizations
 */
/*
function oa_portal_p2_professional_orgs_form_validate($form, &$form_state) {
}
*/

/**
 * Form submission callback for Professional Organizations
 */
/*
function oa_portal_p2_professional_orgs_form_submit($form, &$form_state) {

}
*/


function oa_portal_submit(&$form) {
  $form['#ajax'] = array('enabled' => TRUE);
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Finalize'),
  );
  // DO something else to enable the fancy inline form submission
}


