
#include QMK_KEYBOARD_H
#include <stdio.h>

// QMK

// Initialisieren

typedef struct 
{
    bool is_press_action;
    int state;
} tap;

  
enum 
{
  SINGLE_TAP = 1,
  SINGLE_HOLD = 2,
  DOUBLE_TAP = 3,
  DOUBLE_HOLD = 4
};



enum 
{
    NAV_LAYR = 0,
    FUNC_LAYR,
    PG_LAYR,
    SH_LAYR,
    NR_LAYR,
    SZ_LAYR
};


int origin;  

int cur_dance (tap_dance_state_t *state);


void nav_finished (tap_dance_state_t *state, void *user_data);
void nav_reset (tap_dance_state_t *state, void *user_data);


void pg_finished (tap_dance_state_t *state, void *user_data);
void pg_reset (tap_dance_state_t *state, void *user_data);

void func_finished (tap_dance_state_t *state, void *user_data);
void func_reset (tap_dance_state_t *state, void *user_data);


void sz_finished (tap_dance_state_t *state, void *user_data);
void sz_reset (tap_dance_state_t *state, void *user_data);

void sh_finished (tap_dance_state_t *state, void *user_data);
void sh_reset (tap_dance_state_t *state, void *user_data);

void nr_finished (tap_dance_state_t *state, void *user_data);
void nr_reset (tap_dance_state_t *state, void *user_data);



#define LAYER_Buchstaben 0
#define LAYER_Zahlen 1
#define LAYER_Zahlenlock 2
#define LAYER_Grossbuchstaben 3

#define LAYER_Navigation 4
#define LAYER_dNavigation 5

#define LAYER_Sonderzeichen 6
#define LAYER_dSonderzeichen 7

#define LAYER_Funktionen 8
#define LAYER_dFunktionen 9
#define LAYER_SuperFunction 10

#define LAYER_Programme 11
#define LAYER_dProgramme 12
#define LAYER_SuperProgramme 13

#define LAYER_Nativ 14
#define LAYER_dNativ 15




enum custom_keycodes 
{
    ResetSpace = SAFE_RANGE,
    ResetEnter,
    ResetEsc,
    ModCtl,
    ModCtlGui,
    ModAlt,
    ModCtrlShift,
    ModGui,
    AltShot,
    ResetMacro,
    WinLeft,
    WinRight,
    WinUp,
    WinDown,
    wDoubleTab,
    wPWa0,
    wPWa1,
    wPWa2,
    wPWa3,
    wPWa4,
    wEm0,
    wEm1,
    wEm2,
    wEm3,
    wEm4,
    wGleich,
    wLineDel,
    wSz0,
    wSz1,
    wSz2,
    wSz3,
    wSz4,
    wSz5,
    wSz6,
    wSz7,
    wSz8,
    wSz9,
    wSz10
};




const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = 
{
  
  [LAYER_Buchstaben] = LAYOUT_split_3x6_3(

  KC_ESC, KC_J, KC_D, KC_U, KC_A, KC_X, KC_P, KC_H, KC_L, KC_M, KC_W, KC_BSPC, 
  TD(LN_LAYR), KC_C, KC_T, KC_I, KC_E, KC_O, KC_B, KC_N, KC_R, KC_S, KC_G, TD(RN_LAYR), 
  TD(LS_LAYR), KC_F, KC_V, KC_MINS, KC_Y, KC_Q, KC_Z, KC_SCLN, KC_LBRC, KC_QUOT, KC_K, TD(RS_LAYR),
  TD(LSZ_LAYR), KC_SPC, TD(FUNC_LAYR), TD(PG_LAYR), TD(NAV_LAYR), TD(RSZ_LAYR)),


  [LAYER_Zahlen] = LAYOUT_split_3x6_3(

  KC_ESC, RALT(KC_MINS), LSFT(KC_7) , KC_SLSH, RALT(KC_Q), KC_X, RALT(KC_E), LSFT(KC_DOT), KC_RBRC, LSFT(KC_RBRC), LSFT(KC_COMM), KC_BSPC,
  TD(LN_LAYR), KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, TD(RN_LAYR), 
  TD(LS_LAYR), LSFT(KC_NUHS), KC_NUBS, LSFT(KC_NUBS), LSFT(KC_2), LSFT(KC_SLSH), LSFT(KC_0), KC_DOT, KC_COMM, RALT(KC_RBRC), RALT(KC_NUBS), TD(RS_LAYR), 
  TD(LSZ_LAYR), ResetSpace, TD(FUNC_LAYR), TD(PG_LAYR), TD(NAV_LAYR), TD(RSZ_LAYR)),
  

  [LAYER_Zahlenlock] = LAYOUT_split_3x6_3(
    
  KC_ESC, RALT(KC_MINS), LSFT(KC_7) , KC_SLSH, RALT(KC_Q), KC_X, RALT(KC_E), LSFT(KC_DOT), KC_RBRC, LSFT(KC_RBRC), LSFT(KC_COMM), KC_BSPC,
  TO(LAYER_Zahlenlock), KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, TO(LAYER_Zahlenlock), 
  TD(LS_LAYR), LSFT(KC_NUHS), KC_NUBS, LSFT(KC_NUBS), LSFT(KC_2), LSFT(KC_SLSH), LSFT(KC_0), KC_DOT, KC_COMM, RALT(KC_RBRC), RALT(KC_NUBS), TD(RS_LAYR),
  TD(LSZ_LAYR), KC_SPC, TD(FUNC_LAYR), TD(PG_LAYR), TD(NAV_LAYR), TD(RSZ_LAYR)),


  [LAYER_Grossbuchstaben] = LAYOUT_split_3x6_3(

  KC_ESC, LSFT(KC_J), LSFT(KC_D), LSFT(KC_U), LSFT(KC_A), LSFT(KC_X), LSFT(KC_P), LSFT(KC_H), LSFT(KC_L), LSFT(KC_M), LSFT(KC_W), KC_BSPC,
  TD(LN_LAYR), LSFT(KC_C), LSFT(KC_T), LSFT(KC_I), LSFT(KC_E), LSFT(KC_O), LSFT(KC_B), LSFT(KC_N), LSFT(KC_R), LSFT(KC_S), LSFT(KC_G), TD(RN_LAYR),
  TD(LS_LAYR), LSFT(KC_F), LSFT(KC_V), LSFT(KC_MINS), LSFT(KC_Y), LSFT(KC_Q), LSFT(KC_Z), LSFT(KC_SCLN), LSFT(KC_LBRC), LSFT(KC_QUOT), LSFT(KC_K), TD(RS_LAYR),
  TD(LSZ_LAYR), ResetSpace, TD(FUNC_LAYR), TD(PG_LAYR), TD(NAV_LAYR), TD(RSZ_LAYR)),

  


  [LAYER_Navigation] = LAYOUT_split_3x6_3(

  KC_ESC, LCTL(KC_HOME), LSFT(KC_TAB), KC_UP, KC_TAB, LCTL(KC_Y), AltShot, KC_BSPC, LCA(KC_PGUP), LCTL(KC_PGUP), KC_DEL, LCTL(KC_BSPC), 
  LALT(KC_TAB), LCTL(KC_END), KC_LEFT, KC_DOWN , KC_RGHT, KC_ENT, RCS(KC_F10), KC_LSFT, LCA(KC_PGDN), LCTL(KC_PGDN), KC_LCTL, KC_LALT, 
  LCTL(LGUI(KC_H)), KC_HOME, LCTL(KC_LEFT), LCTL(KC_RGHT), KC_END, LCTL(LGUI(KC_G)), LCTL(LGUI(KC_L)), LCTL(LGUI(KC_A)), RCS(KC_TAB), LCTL(KC_TAB), LCTL(LGUI(KC_B)), LCTL(LGUI(KC_R)),
  TD(LSZ_LAYR), KC_SPC, TD(FUNC_LAYR), TD(PG_LAYR), TD(NAV_LAYR), TD(RSZ_LAYR)),


  [LAYER_dNavigation] = LAYOUT_split_3x6_3(
    
  KC_ESC, RCS(KC_HOME), SGUI(KC_LEFT), WinUp, SGUI(KC_RIGHT), LCA(KC_F11), KC_MUTE, wLineDel, KC_VOLD, KC_VOLU, LSFT(KC_DEL), RCS(KC_BSPC),
  LCA(KC_TAB), RCS(KC_END), WinLeft, WinDown, WinRight, LCA(KC_F12), KC_MPLY, KC_BRIU, KC_MPRV, KC_MNXT, KC_BRID, KC_MSTP, 
  LCTL(LGUI(LSFT(KC_H))), LSFT(KC_HOME), RCS(KC_LEFT), RCS(KC_RGHT), LSFT(KC_END), LCTL(LGUI(LSFT(KC_G))), LCTL(LGUI(LSFT(KC_L))), LCTL(LGUI(LSFT(KC_A))), LCA(KC_LEFT), LCA(KC_RIGHT), LCTL(LGUI(LSFT(KC_B))), LCTL(LGUI(LSFT(KC_R))),
  TD(LSZ_LAYR), KC_SPC, TD(FUNC_LAYR), TD(PG_LAYR), TD(NAV_LAYR), TD(RSZ_LAYR)),

 




  [LAYER_Sonderzeichen] = LAYOUT_split_3x6_3(
    
  KC_LCTL, RALT(KC_MINS), LSFT(KC_7) , KC_SLSH, RALT(KC_Q), LSFT(KC_5), RALT(KC_E), LSFT(KC_DOT), KC_RBRC, LSFT(KC_RBRC), LSFT(KC_COMM), KC_BSPC,
  LALT(KC_TAB), LSFT(KC_6), RALT(KC_8), RALT(KC_9), KC_BSLS, RALT(KC_7), RALT(KC_0), LSFT(KC_1), LSFT(KC_8), LSFT(KC_9), LSFT(KC_MINS), KC_CIRC,
  KC_LSFT, LSFT(KC_NUHS), KC_NUBS, LSFT(KC_NUBS), LSFT(KC_2), LSFT(KC_SLSH), LSFT(KC_0), KC_DOT, KC_COMM, RALT(KC_RBRC), RALT(KC_NUBS), LGUI(KC_DOT), 
  TD(LSZ_LAYR), ResetMacro, TD(FUNC_LAYR), TD(PG_LAYR), TD(NAV_LAYR), TD(RSZ_LAYR)),


  [LAYER_dSonderzeichen] = LAYOUT_split_3x6_3(

  QK_BOOT, LSFT(KC_GRV), LSFT(KC_EQL), KC_EQL, KC_GRV, wSz0, LSFT(KC_4), RALT(KC_2), LSFT(KC_3), RALT(KC_M), RALT(KC_3), QK_BOOT, 
  wDoubleTab, wEm4, wEm3, wEm2, wEm1, wEm0, wPWa0, wPWa1, wPWa2, wPWa3, wPWa4, KC_CIRC,
  LCTL(KC_LSFT), wSz1, wSz2, wSz3, wSz4, wSz5, wSz6, wSz7, wSz8, wSz9, wSz10,  LGUI(KC_DOT),
  TD(LSZ_LAYR), ResetMacro, TD(FUNC_LAYR), TD(PG_LAYR), TD(NAV_LAYR), TD(RSZ_LAYR)),








  [LAYER_Funktionen] = LAYOUT_split_3x6_3(

  LCA(KC_I), LCA(KC_F1), LCA(KC_F2), LCA(KC_F3), LCA(KC_F4), LCA(KC_F5), LCA(KC_F6), LCA(KC_F7), LCA(KC_F8), LCA(KC_F9), LCA(KC_F10), LCA(KC_X),
  LCA(KC_K), LCTL(KC_A), LCA(KC_A), LCA(KC_B), LCTL(KC_C), LCTL(KC_X), LCA(KC_O), LCTL(KC_V), LCA(KC_T), LCA(KC_U), LCA(KC_L), LCA(KC_W),
  LCA(KC_J), LCA(KC_S), LGUI(KC_DEL), LGUI(KC_INSERT), LCTL(KC_DEL), LCA(KC_G), LCA(KC_H), LCA(KC_F), LCA(KC_D), LCA(KC_C), LCA(KC_E), LCA(KC_Z),
  TD(LSZ_LAYR), OSL(LAYER_SuperFunction), TD(FUNC_LAYR), OSL(LAYER_Nativ), ModCtl, TD(RSZ_LAYR)),


  [LAYER_dFunktionen] = LAYOUT_split_3x6_3(

  MEH(KC_I), MEH(KC_F1), MEH(KC_F2), MEH(KC_F3), MEH(KC_F4), MEH(KC_F5), MEH(KC_F6), MEH(KC_F7), MEH(KC_F8), MEH(KC_F9), MEH(KC_F10), MEH(KC_X),
  MEH(KC_K), MEH(KC_P), MEH(KC_A), MEH(KC_B), MEH(KC_C), RCS(KC_X), MEH(KC_O), MEH(KC_V), MEH(KC_T), MEH(KC_U), LGUI(KC_V), MEH(KC_W),
  MEH(KC_J), MEH(KC_S), MEH(KC_N), MEH(KC_M), MEH(KC_R), MEH(KC_G), MEH(KC_H), MEH(KC_F), MEH(KC_D), MEH(KC_C),  MEH(KC_E), MEH(KC_Z),
  TD(LSZ_LAYR), ModGui, TD(FUNC_LAYR), OSL(LAYER_dNativ), ModCtrlShift, TD(RSZ_LAYR)),


  [LAYER_SuperFunction] = LAYOUT_split_3x6_3(

  LCTL(KC_F1), RCS(KC_P), LCTL(KC_PPLS), KC_PGUP, RCS(KC_R), RCS(KC_G), LCAG(KC_A), LCAG(KC_B), LCAG(KC_C), LCAG(KC_D), LCAG(KC_E), LCAG(KC_F),
  LCA(KC_TAB), LCTL(KC_P), LCTL(KC_PMNS), KC_PGDN, LCTL(KC_R), LCTL(KC_G), LCAG(KC_G), LCAG(KC_I), LCAG(KC_J), LCAG(KC_K), LCAG(KC_L), LCAG(KC_M),
  RCS(KC_S), LCTL(KC_S), LCTL(KC_Y), LCTL(KC_Z), LCAG(KC_W), SGUI(KC_S), LCAG(KC_N), LCAG(KC_O), LCAG(KC_P), LCAG(KC_Q), LCAG(KC_R), LCAG(KC_S),
  TD(LSZ_LAYR), KC_SPC, TD(FUNC_LAYR), TD(PG_LAYR), ModAlt, TD(RSZ_LAYR)),







 [LAYER_Programme] = LAYOUT_split_3x6_3(
    
  LALT(KC_F4), RSG(KC_1), RSG(KC_2), RSG(KC_3), RSG(KC_4), RSG(KC_5), LAG(KC_F1), LAG(KC_F2), LAG(KC_F3), LAG(KC_F4), LAG(KC_F5), LAG(KC_F6),
  RSG(KC_6), LCTL(LGUI(KC_1)), LCTL(LGUI(KC_2)), LCTL(LGUI(KC_3)), LCTL(LGUI(KC_4)), LCTL(LGUI(KC_5)), LCAG(KC_F1), LCAG(KC_F2), LCAG(KC_F3), LCAG(KC_F4), LCAG(KC_F5), LCAG(KC_F6),
  RSG(KC_7), LCTL(LGUI(KC_6)), LCTL(LGUI(KC_7)), LCTL(LGUI(KC_8)), LCTL(LGUI(KC_9)), LCTL(LGUI(KC_0)), LCAG(KC_F7), LCAG(KC_F8), LCAG(KC_F9), LCAG(KC_F10), LCAG(KC_F11), LCAG(KC_F12),
  TD(LSZ_LAYR), LCAG(KC_X), OSL(LAYER_Nativ), TD(PG_LAYR), OSL(LAYER_SuperProgramme), TD(RSZ_LAYR)),


  [LAYER_dProgramme] = LAYOUT_split_3x6_3(
  
  RCS(KC_ESC), LSA(KC_1), LSA(KC_2), LSA(KC_3), LSA(KC_4), LSA(KC_5), LAG(KC_F7), LAG(KC_F8), LAG(KC_F9), LAG(KC_F10), LAG(KC_F11), LAG(KC_F12),
  LSA(KC_6), LCAG(KC_1), LCAG(KC_2), LCAG(KC_3), LCAG(KC_4), LCAG(KC_5), SGUI(KC_F1), SGUI(KC_F2), SGUI(KC_F3), SGUI(KC_F4), SGUI(KC_F5), SGUI(KC_F6),
  LSA(KC_7), LCAG(KC_6), LCAG(KC_7), LCAG(KC_8), LCAG(KC_9), LCAG(KC_0), SGUI(KC_F7), SGUI(KC_F8), SGUI(KC_F9), SGUI(KC_F10), SGUI(KC_F11), SGUI(KC_F12),
  TD(LSZ_LAYR), LCAG(KC_Y), OSL(LAYER_dNativ), TD(PG_LAYR), OSL(LAYER_SuperProgramme), TD(RSZ_LAYR)),
  

  [LAYER_SuperProgramme] = LAYOUT_split_3x6_3(

  SGUI(KC_A), SGUI(KC_B), SGUI(KC_C), SGUI(KC_D), SGUI(KC_E), SGUI(KC_F), LAG(KC_F7), LAG(KC_F8), LAG(KC_F9), LAG(KC_F10), LAG(KC_F11), LAG(KC_F12),
  SGUI(KC_G), SGUI(KC_I), SGUI(KC_J), SGUI(KC_K), SGUI(KC_L), SGUI(KC_M), SGUI(KC_F1), SGUI(KC_F2), SGUI(KC_F3), SGUI(KC_F4), SGUI(KC_F5), SGUI(KC_F6),
  SGUI(KC_N), SGUI(KC_O), SGUI(KC_P), SGUI(KC_Q), SGUI(KC_R), SGUI(KC_S), SGUI(KC_F7), SGUI(KC_F8), SGUI(KC_F9), SGUI(KC_F10), SGUI(KC_F11), SGUI(KC_F12),
  TD(LSZ_LAYR), LCAG(KC_Z), TD(FUNC_LAYR), TD(PG_LAYR), TD(NAV_LAYR), TD(RSZ_LAYR)),





  [LAYER_Nativ] = LAYOUT_split_3x6_3(

  KC_LCTL, LALT(KC_1), LALT(KC_2), LALT(KC_3), LALT(KC_4), LALT(KC_5), LALT(KC_6), LALT(KC_7), LALT(KC_8), LALT(KC_9), LALT(KC_0), KC_LCTL,
  KC_F11, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F12,
  KC_LSFT, LCTL(KC_1), LCTL(KC_2), LCTL(KC_3), LCTL(KC_4), LCTL(KC_5), LCTL(KC_6), LCTL(KC_7), LCTL(KC_8), LCTL(KC_9), LCTL(KC_0), KC_RSFT,
  TD(LSZ_LAYR), KC_SPC, TD(FUNC_LAYR),  TD(PG_LAYR), TD(NAV_LAYR), TD(RSZ_LAYR)),


  [LAYER_dNativ] = LAYOUT_split_3x6_3(  
    
  RGB_TOG, RGB_M_G, RGB_M_P, RGB_M_R, RGB_M_X, RGB_TOG, RGB_SPI, RGB_VAI, RGB_SAI, RGB_HUI, BL_UP, RGB_MOD,
  LCTL(KC_F11), LCTL(KC_F1), LCTL(KC_F2), LCTL(KC_F3), LCTL(KC_F4), LCTL(KC_F5), LCTL(KC_F6), LCTL(KC_F7), LCTL(KC_F8), LCTL(KC_F9), LCTL(KC_F10), LCTL(KC_F12),
  BL_TOGG, RGB_M_SW, RGB_M_K, RGB_M_T, RGB_M_B, RGB_M_SN, RGB_SPD, RGB_VAD, RGB_SAD, RGB_HUD, BL_DOWN, RGB_RMOD, 
  TD(LSZ_LAYR), KC_SPC, TD(FUNC_LAYR), TD(PG_LAYR), TD(NAV_LAYR), TD(RSZ_LAYR)),




};





// Dance State Initialisieren

int cur_dance (tap_dance_state_t *state) 
{

  if (state->count == 1)
  {
    if (state->pressed)
       return SINGLE_HOLD;
    else 
      return SINGLE_TAP;
  }
  else 
  {
    if (state->count == 2) 
    {
      if (state->pressed) 
        return DOUBLE_HOLD;
      else 
        return DOUBLE_TAP;
    }
  }
    return DOUBLE_TAP;
}




//Tap State initialisieren

static tap ql_tap_state = 
{
  .is_press_action = true,
  .state = 0
};





//------ NAV ------------------------------------------

void nav_finished (tap_dance_state_t *state, void *user_data) 
{

  ql_tap_state.state = cur_dance(state);

  switch (ql_tap_state.state) {

    case SINGLE_TAP: 

      clear_oneshot_mods();
      clear_mods();

      layer_off(LAYER_Zahlen);layer_off(LAYER_Grossbuchstaben);
      layer_off(LAYER_Navigation);layer_off(LAYER_dNavigation);
      layer_off(LAYER_dProgramme);layer_off(LAYER_dNativ);
      layer_off(LAYER_Funktionen);layer_off(LAYER_dFunktionen);
      layer_off(LAYER_SuperFunction);layer_off(LAYER_SuperProgramme);
      layer_off(LAYER_Programme);layer_off(LAYER_Nativ);
      layer_off(LAYER_Sonderzeichen);layer_off(LAYER_dSonderzeichen);
     
      set_oneshot_layer(LAYER_Navigation, ONESHOT_START); clear_oneshot_layer_state(ONESHOT_PRESSED); 
      break;

    case SINGLE_HOLD: 

      clear_oneshot_mods();
      clear_mods();

      layer_off(LAYER_Zahlen);layer_off(LAYER_Grossbuchstaben);
      layer_off(LAYER_Navigation);layer_off(LAYER_dNavigation);
      layer_off(LAYER_dProgramme);layer_off(LAYER_dNativ);
      layer_off(LAYER_Funktionen);layer_off(LAYER_dFunktionen);
      layer_off(LAYER_SuperFunction);layer_off(LAYER_SuperProgramme);
      layer_off(LAYER_Programme);layer_off(LAYER_Nativ);
      layer_off(LAYER_Sonderzeichen);layer_off(LAYER_dSonderzeichen);
    
      layer_on(LAYER_Navigation);
      break;

    case DOUBLE_TAP: 
      
      clear_oneshot_mods();
      clear_mods();

      layer_off(LAYER_Zahlen);layer_off(LAYER_Grossbuchstaben);
      layer_off(LAYER_Navigation);layer_off(LAYER_dNavigation);
      layer_off(LAYER_dProgramme);layer_off(LAYER_dNativ);
      layer_off(LAYER_Funktionen);layer_off(LAYER_dFunktionen);
      layer_off(LAYER_SuperFunction);layer_off(LAYER_SuperProgramme);
      layer_off(LAYER_Programme);layer_off(LAYER_Nativ);
      layer_off(LAYER_Sonderzeichen);layer_off(LAYER_dSonderzeichen);

      set_oneshot_layer(LAYER_dNavigation, ONESHOT_START); clear_oneshot_layer_state(ONESHOT_PRESSED); 
      break;

    case DOUBLE_HOLD:
       
      clear_oneshot_mods();
      clear_mods();

      layer_off(LAYER_Zahlen);layer_off(LAYER_Grossbuchstaben);
      layer_off(LAYER_Navigation);layer_off(LAYER_dNavigation);
      layer_off(LAYER_dProgramme);layer_off(LAYER_dNativ);
      layer_off(LAYER_Funktionen);layer_off(LAYER_dFunktionen);
      layer_off(LAYER_SuperFunction);layer_off(LAYER_SuperProgramme);
      layer_off(LAYER_Programme);layer_off(LAYER_Nativ);
      layer_off(LAYER_Sonderzeichen);layer_off(LAYER_dSonderzeichen);
    
      layer_on(LAYER_dNavigation);
      break;
  }
}

void nav_reset (tap_dance_state_t *state, void *user_data) 
{
    switch (ql_tap_state.state) {
      case SINGLE_TAP: break; 
      case SINGLE_HOLD: layer_off(LAYER_Navigation); layer_off(LAYER_Funktionen); break; 
      case DOUBLE_TAP: break;
      case DOUBLE_HOLD: layer_off(LAYER_dNavigation); layer_off(LAYER_Funktionen); break; 
    }
    ql_tap_state.state = 0;
}









//------ FUNC ------------------------------------------

void func_finished (tap_dance_state_t *state, void *user_data)
{
  ql_tap_state.state = cur_dance(state);
  switch (ql_tap_state.state) {
    case SINGLE_TAP: 

      clear_oneshot_mods();
      clear_mods();

      layer_off(LAYER_Zahlen);layer_off(LAYER_Grossbuchstaben);
      layer_off(LAYER_Navigation);layer_off(LAYER_dNavigation);
      layer_off(LAYER_dProgramme);layer_off(LAYER_dNativ);
      layer_off(LAYER_Funktionen);layer_off(LAYER_dFunktionen);
      layer_off(LAYER_SuperFunction);layer_off(LAYER_SuperProgramme);
      layer_off(LAYER_Programme);layer_off(LAYER_Nativ);
      layer_off(LAYER_Sonderzeichen);layer_off(LAYER_dSonderzeichen);

      set_oneshot_layer(LAYER_Funktionen, ONESHOT_START); clear_oneshot_layer_state(ONESHOT_PRESSED);
      break;

    case SINGLE_HOLD: 

      clear_oneshot_mods();
      clear_mods();

      layer_off(LAYER_Zahlen);layer_off(LAYER_Grossbuchstaben);
      layer_off(LAYER_Navigation);layer_off(LAYER_dNavigation);
      layer_off(LAYER_dProgramme);layer_off(LAYER_dNativ);
      layer_off(LAYER_Funktionen);layer_off(LAYER_dFunktionen);
      layer_off(LAYER_SuperFunction);layer_off(LAYER_SuperProgramme);
      layer_off(LAYER_Programme);layer_off(LAYER_Nativ);
      layer_off(LAYER_Sonderzeichen);layer_off(LAYER_dSonderzeichen);

      layer_on(LAYER_Funktionen); 
      break;

    case DOUBLE_TAP: 

      clear_oneshot_mods();
      clear_mods();

      layer_off(LAYER_Zahlen);layer_off(LAYER_Grossbuchstaben);
      layer_off(LAYER_Navigation);layer_off(LAYER_dNavigation);
      layer_off(LAYER_dProgramme);layer_off(LAYER_dNativ);
      layer_off(LAYER_Funktionen);layer_off(LAYER_dFunktionen);
      layer_off(LAYER_SuperFunction);layer_off(LAYER_SuperProgramme);
      layer_off(LAYER_Programme);layer_off(LAYER_Nativ);
      layer_off(LAYER_Sonderzeichen);layer_off(LAYER_dSonderzeichen);

      set_oneshot_layer(LAYER_dFunktionen, ONESHOT_START); clear_oneshot_layer_state(ONESHOT_PRESSED);
      break;
      
    case DOUBLE_HOLD:

      clear_oneshot_mods();
      clear_mods();

      layer_off(LAYER_Zahlen);layer_off(LAYER_Grossbuchstaben);
      layer_off(LAYER_Navigation);layer_off(LAYER_dNavigation);
      layer_off(LAYER_dProgramme);layer_off(LAYER_dNativ);
      layer_off(LAYER_Funktionen);layer_off(LAYER_dFunktionen);
      layer_off(LAYER_SuperFunction);layer_off(LAYER_SuperProgramme);
      layer_off(LAYER_Programme);layer_off(LAYER_Nativ);
      layer_off(LAYER_Sonderzeichen);layer_off(LAYER_dSonderzeichen);

      layer_on(LAYER_dFunktionen); 
      break;
  }
}

void func_reset (tap_dance_state_t *state, void *user_data) 
{
    switch (ql_tap_state.state) {
        case SINGLE_TAP: break;
        case SINGLE_HOLD: layer_off(LAYER_Funktionen); break;
        case DOUBLE_TAP: break; 
        case DOUBLE_HOLD: layer_off(LAYER_dFunktionen);break;
    }
    ql_tap_state.state = 0;
}




//------ PG ------------------------------------------

void pg_finished (tap_dance_state_t *state, void *user_data) 
{
  ql_tap_state.state = cur_dance(state);
  switch (ql_tap_state.state) {
    case SINGLE_TAP: 

      clear_oneshot_mods();
      clear_mods();

      layer_off(LAYER_Zahlen);layer_off(LAYER_Grossbuchstaben);
      layer_off(LAYER_Navigation);layer_off(LAYER_dNavigation);
      layer_off(LAYER_dProgramme);layer_off(LAYER_dNativ);
      layer_off(LAYER_Funktionen);layer_off(LAYER_dFunktionen);
      layer_off(LAYER_SuperFunction);layer_off(LAYER_SuperProgramme);
      layer_off(LAYER_Programme);layer_off(LAYER_Nativ);
      layer_off(LAYER_Sonderzeichen);layer_off(LAYER_dSonderzeichen);

      set_oneshot_layer(LAYER_Programme, ONESHOT_START); clear_oneshot_layer_state(ONESHOT_PRESSED);
      break;

    case SINGLE_HOLD: 

      clear_oneshot_mods();
      clear_mods();

      layer_off(LAYER_Zahlen);layer_off(LAYER_Grossbuchstaben);
      layer_off(LAYER_Navigation);layer_off(LAYER_dNavigation);
      layer_off(LAYER_dProgramme);layer_off(LAYER_dNativ);
      layer_off(LAYER_Funktionen);layer_off(LAYER_dFunktionen);
      layer_off(LAYER_SuperFunction);layer_off(LAYER_SuperProgramme);
      layer_off(LAYER_Programme);layer_off(LAYER_Nativ);
      layer_off(LAYER_Sonderzeichen);layer_off(LAYER_dSonderzeichen);
      
      layer_on(LAYER_Programme); 
      break;

    case DOUBLE_TAP: 

      clear_oneshot_mods();
      clear_mods();

      layer_off(LAYER_Zahlen);layer_off(LAYER_Grossbuchstaben);
      layer_off(LAYER_Navigation);layer_off(LAYER_dNavigation);
      layer_off(LAYER_dProgramme);layer_off(LAYER_dNativ);
      layer_off(LAYER_Funktionen);layer_off(LAYER_dFunktionen);
      layer_off(LAYER_SuperFunction);layer_off(LAYER_SuperProgramme);
      layer_off(LAYER_Programme);layer_off(LAYER_Nativ);
      layer_off(LAYER_Sonderzeichen);layer_off(LAYER_dSonderzeichen);

      set_oneshot_layer(LAYER_dProgramme, ONESHOT_START); clear_oneshot_layer_state(ONESHOT_PRESSED);
      break;
      
    case DOUBLE_HOLD:

      clear_oneshot_mods();
      clear_mods();

      layer_off(LAYER_Zahlen);layer_off(LAYER_Grossbuchstaben);
      layer_off(LAYER_Navigation);layer_off(LAYER_dNavigation);
      layer_off(LAYER_dProgramme);layer_off(LAYER_dNativ);
      layer_off(LAYER_Funktionen);layer_off(LAYER_dFunktionen);
      layer_off(LAYER_SuperFunction);layer_off(LAYER_SuperProgramme);
      layer_off(LAYER_Programme);layer_off(LAYER_Nativ);
      layer_off(LAYER_Sonderzeichen);layer_off(LAYER_dSonderzeichen);

      layer_on(LAYER_dProgramme); 
      break;
  }
}


void pg_reset (tap_dance_state_t *state, void *user_data) 
{
    switch (ql_tap_state.state) {
        case SINGLE_TAP:  break;
        case SINGLE_HOLD: layer_off(LAYER_Programme);break;
        case DOUBLE_TAP:  break;
        case DOUBLE_HOLD: layer_off(LAYER_dProgramme);break;
    }
    ql_tap_state.state = 0;
}






//------  Shift ------------------------------------------

void sh_finished (tap_dance_state_t *state, void *user_data) 
{
  ql_tap_state.state = cur_dance(state);
  switch (ql_tap_state.state) {
    case SINGLE_TAP: 

      clear_oneshot_mods();
      clear_mods();

      layer_off(LAYER_Navigation);layer_off(LAYER_dNavigation);
      layer_off(LAYER_dProgramme);layer_off(LAYER_dNativ);
      layer_off(LAYER_Funktionen);layer_off(LAYER_dFunktionen);
      layer_off(LAYER_SuperFunction);layer_off(LAYER_SuperProgramme);
      layer_off(LAYER_Programme);layer_off(LAYER_Nativ);
      layer_off(LAYER_Sonderzeichen);layer_off(LAYER_dSonderzeichen);

      set_oneshot_layer(LAYER_Grossbuchstaben, ONESHOT_START); clear_oneshot_layer_state(ONESHOT_PRESSED);
      break;

    case SINGLE_HOLD: 

      clear_oneshot_mods();
      clear_mods();

      layer_off(LAYER_Navigation);layer_off(LAYER_dNavigation);
      layer_off(LAYER_dProgramme);layer_off(LAYER_dNativ);
      layer_off(LAYER_Funktionen);layer_off(LAYER_dFunktionen);
      layer_off(LAYER_SuperFunction);layer_off(LAYER_SuperProgramme);
      layer_off(LAYER_Programme);layer_off(LAYER_Nativ);
      layer_off(LAYER_Sonderzeichen);layer_off(LAYER_dSonderzeichen);
      
      layer_on(LAYER_Grossbuchstaben); 
      break;

    case DOUBLE_TAP: 

      clear_oneshot_mods();
      clear_mods();

      layer_off(LAYER_Navigation);layer_off(LAYER_dNavigation);
      layer_off(LAYER_dProgramme);layer_off(LAYER_dNativ);
      layer_off(LAYER_Funktionen);layer_off(LAYER_dFunktionen);
      layer_off(LAYER_SuperFunction);layer_off(LAYER_SuperProgramme);
      layer_off(LAYER_Programme);layer_off(LAYER_Nativ);
      layer_off(LAYER_Sonderzeichen);layer_off(LAYER_dSonderzeichen);

      layer_on(LAYER_Grossbuchstaben); 
      break;
      
    case DOUBLE_HOLD:

      clear_oneshot_mods();
      clear_mods();

      layer_off(LAYER_Navigation);layer_off(LAYER_dNavigation);
      layer_off(LAYER_dProgramme);layer_off(LAYER_dNativ);
      layer_off(LAYER_Funktionen);layer_off(LAYER_dFunktionen);
      layer_off(LAYER_SuperFunction);layer_off(LAYER_SuperProgramme);
      layer_off(LAYER_Programme);layer_off(LAYER_Nativ);
      layer_off(LAYER_Sonderzeichen);layer_off(LAYER_dSonderzeichen);

      layer_on(LAYER_Grossbuchstaben); 
      break;
  }
}


void sh_reset (tap_dance_state_t *state, void *user_data) 
{
    switch (ql_tap_state.state) {
        case SINGLE_TAP:  break;
        case SINGLE_HOLD: layer_off(LAYER_Grossbuchstaben);break;
        case DOUBLE_TAP:  break;
        case DOUBLE_HOLD: break;
    }
    ql_tap_state.state = 0;
}










//------ Sonderzeichen ------------------------------------------

void sz_finished (tap_dance_state_t *state, void *user_data) 
{

  ql_tap_state.state = cur_dance(state);

  switch (ql_tap_state.state) {

    case SINGLE_TAP: 

      clear_oneshot_mods();
      clear_mods();

      layer_off(LAYER_Navigation);layer_off(LAYER_dNavigation);
      layer_off(LAYER_dProgramme);layer_off(LAYER_dNativ);
      layer_off(LAYER_Funktionen);layer_off(LAYER_dFunktionen);
      layer_off(LAYER_SuperFunction);layer_off(LAYER_SuperProgramme);
      layer_off(LAYER_Programme);layer_off(LAYER_Nativ);
      layer_off(LAYER_Sonderzeichen);layer_off(LAYER_dSonderzeichen);

      set_oneshot_layer(LAYER_Sonderzeichen, ONESHOT_START); clear_oneshot_layer_state(ONESHOT_PRESSED);
      break;

    case SINGLE_HOLD:

      clear_oneshot_mods();
      clear_mods();

      layer_off(LAYER_Navigation);layer_off(LAYER_dNavigation);
      layer_off(LAYER_dProgramme);layer_off(LAYER_dNativ);
      layer_off(LAYER_Funktionen);layer_off(LAYER_dFunktionen);
      layer_off(LAYER_SuperFunction);layer_off(LAYER_SuperProgramme);
      layer_off(LAYER_Programme);layer_off(LAYER_Nativ);
      layer_off(LAYER_Sonderzeichen);layer_off(LAYER_dSonderzeichen);
      
      layer_on(LAYER_Sonderzeichen);
      break;

    case DOUBLE_TAP: 
      clear_oneshot_mods();
      clear_mods();

      layer_off(LAYER_Navigation);layer_off(LAYER_dNavigation);
      layer_off(LAYER_dProgramme);layer_off(LAYER_dNativ);
      layer_off(LAYER_Funktionen);layer_off(LAYER_dFunktionen);
      layer_off(LAYER_SuperFunction);layer_off(LAYER_SuperProgramme);
      layer_off(LAYER_Programme);layer_off(LAYER_Nativ);
      layer_off(LAYER_Sonderzeichen);layer_off(LAYER_dSonderzeichen);

      set_oneshot_layer(LAYER_dSonderzeichen, ONESHOT_START); clear_oneshot_layer_state(ONESHOT_PRESSED);
      break;

    case DOUBLE_HOLD:
      clear_oneshot_mods();
      clear_mods();

      layer_off(LAYER_Navigation);layer_off(LAYER_dNavigation);
      layer_off(LAYER_dProgramme);layer_off(LAYER_dNativ);
      layer_off(LAYER_Funktionen);layer_off(LAYER_dFunktionen);
      layer_off(LAYER_SuperFunction);layer_off(LAYER_SuperProgramme);
      layer_off(LAYER_Programme);layer_off(LAYER_Nativ);
      layer_off(LAYER_Sonderzeichen);layer_off(LAYER_dSonderzeichen);

      layer_on(LAYER_dSonderzeichen);
      break;
  }
}

void sz_reset (tap_dance_state_t *state, void *user_data) 
{
    switch (ql_tap_state.state) {
      case SINGLE_TAP: break; 
      case SINGLE_HOLD: layer_off(LAYER_Sonderzeichen);break;
      case DOUBLE_TAP:  break; 
      case DOUBLE_HOLD: layer_off(LAYER_dSonderzeichen);break;
    }
    ql_tap_state.state = 0;
}










//------ Nummer ------------------------------------------

void nr_finished (tap_dance_state_t *state, void *user_data) 
{
  ql_tap_state.state = cur_dance(state);
  switch (ql_tap_state.state) {
    case SINGLE_TAP: 

      clear_oneshot_mods();
      clear_mods();
      layer_clear();

      layer_on(LAYER_Zahlen);
      break;

    case SINGLE_HOLD: 

      clear_oneshot_mods();
      clear_mods();
      layer_clear();

      layer_on(LAYER_Zahlen);
      break;

    case DOUBLE_TAP: 

      clear_oneshot_mods();
      layer_clear();
      clear_mods();

      layer_on(LAYER_Zahlenlock);
      break;
      
    case DOUBLE_HOLD:

      clear_oneshot_mods();
      layer_clear();
      clear_mods();

      layer_on(LAYER_Zahlenlock);
      break;
  }
}


void nr_reset (tap_dance_state_t *state, void *user_data) 
{
    switch (ql_tap_state.state) {
        case SINGLE_TAP:  break;
        case SINGLE_HOLD: layer_off(LAYER_Grossbuchstaben);break;
        case DOUBLE_TAP:  break;
        case DOUBLE_HOLD: layer_off(LAYER_Grossbuchstaben);break;
    }
    ql_tap_state.state = 0;
}








// Dance Key mit der Funktionalität zuweisen

tap_dance_action_t tap_dance_actions[] = 
{
  [NAV_LAYR] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, nav_finished, nav_reset),
  [PG_LAYR] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, pg_finished, pg_reset),
  [FUNC_LAYR] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, func_finished, func_reset),
  [SH_LAYR] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, sh_finished, sh_reset),
  [NR_LAYR] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, nr_finished, nr_reset),
  [SZ_LAYR] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, sz_finished, sz_reset),
};







// Macro

bool process_record_user(uint16_t keycode, keyrecord_t *record) 
{

  switch (keycode) 
  {
    
    case wSz0:
    if (record->event.pressed) 
    {
      register_code(KC_LSFT);
      tap_code(KC_0);
      tap_code(KC_NUBS);
      unregister_code(KC_LSFT);
    
      return false;
    }
    break;

    case wSz1:
      if (record->event.pressed) 
      {
        register_code(KC_LSFT);
        tap_code(KC_0);
        tap_code(KC_NUBS);
        unregister_code(KC_LSFT);
      
        return false;
      }
    break;

    case wSz2:
    if (record->event.pressed) 
    {
      register_code(KC_LSFT);
      tap_code(KC_0);
      tap_code(KC_NUBS);
      unregister_code(KC_LSFT);
    
      return false;
    }
    break;

    case wSz3:
    if (record->event.pressed) 
    {
      register_code(KC_LSFT);
      tap_code(KC_0);
      tap_code(KC_NUBS);
      unregister_code(KC_LSFT);
    
      return false;
    }
    break;

    case wSz4:
    if (record->event.pressed) 
    {
      register_code(KC_LSFT);
      tap_code(KC_0);
      tap_code(KC_NUBS);
      unregister_code(KC_LSFT);
    
      return false;
    }
    break;

    case wSz5:
    if (record->event.pressed) 
    {
      register_code(KC_LSFT);
      tap_code(KC_0);
      tap_code(KC_NUBS);
      unregister_code(KC_LSFT);
    
      return false;
    }
    break;

    case wSz6:
    if (record->event.pressed) 
    {
      register_code(KC_LSFT);
      tap_code(KC_0);
      tap_code(KC_NUBS);
      unregister_code(KC_LSFT);
    
      return false;
    }
    break;

    case wSz7:
    if (record->event.pressed) 
    {
      register_code(KC_LSFT);
      tap_code(KC_0);
      tap_code(KC_NUBS);
      unregister_code(KC_LSFT);
    
      return false;
    }
    break;

    case wSz8:
    if (record->event.pressed) 
    {
      register_code(KC_LSFT);
      tap_code(KC_0);
      tap_code(KC_NUBS);
      unregister_code(KC_LSFT);
    
      return false;
    }
    break;

    case wSz9:
    if (record->event.pressed) 
    {
      register_code(KC_LSFT);
      tap_code(KC_0);
      tap_code(KC_NUBS);
      unregister_code(KC_LSFT);
    
      return false;
    }
    break;

    case wSz10:
    if (record->event.pressed) 
    {
      register_code(KC_LSFT);
      tap_code(KC_0);
      tap_code(KC_NUBS);
      unregister_code(KC_LSFT);
    
      return false;
    }
    break;

    
    case wGleich:
      if (record->event.pressed) 
      {
        register_code(KC_LSFT);
        tap_code(KC_0);
        tap_code(KC_NUBS);
        unregister_code(KC_LSFT);
      
        return false;
      }
    break;





    case ResetSpace:
      if (record->event.pressed) 
      {
        tap_code(KC_SPC);
        layer_clear();
        return false;
      }
    break;

    case ResetEnter:
      if (record->event.pressed) 
      {
        tap_code(KC_ENT);
        layer_clear();
        return false;
      }
    break;

    case ResetEsc:
      if (record->event.pressed) 
      {
        tap_code(KC_ESC);
        layer_clear();
        return false;
      }
    break;






    case ModCtl:
      if (record->event.pressed)
      {
        layer_clear();
        clear_oneshot_mods();
        set_oneshot_mods(MOD_LCTL);     
        return false;
      }
    break;

    case ModCtlGui:
      if (record->event.pressed)
      {
        layer_clear();
        clear_oneshot_mods();
        set_oneshot_mods(MOD_LGUI | MOD_LCTL);    
        return false;
      }
    break;


    case ModAlt:
      if (record->event.pressed)
      {
        layer_clear();
        clear_oneshot_mods();
        set_oneshot_mods(MOD_LALT);     
        return false;
      }
    break;

    case ModCtrlShift:
      if (record->event.pressed) 
      {
        layer_clear();
        clear_oneshot_mods();
        set_oneshot_mods(MOD_LCTL | MOD_LSFT);       
        return false;
      }
    break;

    case ModGui:
      if (record->event.pressed) 
      {
        layer_clear();
        clear_oneshot_mods();
        set_oneshot_mods(MOD_LGUI);      
        return false;
      }
    break;






    case AltShot:
      if (record->event.pressed) 
      {
        register_code(KC_LALT);
        unregister_code(KC_LALT);   
        return false;
      }
    break;




    case wLineDel:
      if (record->event.pressed)
      {
        register_code(KC_LSFT);
        tap_code(KC_HOME);
        unregister_code(KC_LSFT);
        tap_code(KC_BSPC);
        return false;
      }
    break;


    case ResetMacro:
      if (record->event.pressed)
      {
        clear_mods();
        register_code(KC_LGUI);
        register_code(KC_LCTL);
        register_code(KC_NUBS);
        unregister_code(KC_NUBS);
        unregister_code(KC_LGUI);
        unregister_code(KC_LCTL);

        clear_oneshot_layer_state(ONESHOT_PRESSED);
        clear_oneshot_mods();
        layer_clear();

        unregister_code(KC_LGUI);
        unregister_code(KC_RGUI);
        unregister_code(KC_LCTL);
        unregister_code(KC_RCTL);
        unregister_code(KC_LALT);
        unregister_code(KC_RALT);
        unregister_code(KC_LSFT);
        unregister_code(KC_RSFT);
      return false;
      }
    break;


    case WinLeft:
      if (record->event.pressed) 
      {
        register_code(KC_LGUI); 
        tap_code(KC_LEFT);
        _delay_ms(250);    
        unregister_code(KC_LGUI);
        return false;
      }
    break;

    case WinRight:
      if (record->event.pressed)
      {
        register_code(KC_LGUI); 
        tap_code(KC_RIGHT);
        _delay_ms(250);    
        unregister_code(KC_LGUI);
        return false;
      }
    break;

    case WinUp:
      if (record->event.pressed) 
      {
        register_code(KC_LGUI);
        tap_code(KC_UP);
        _delay_ms(250);    
        unregister_code(KC_LGUI);
        return false;
      }
    break;

    case WinDown:
      if (record->event.pressed) 
      {
        register_code(KC_LGUI); 
        tap_code(KC_DOWN);
        _delay_ms(250);    
        unregister_code(KC_LGUI);
        return false;
      }
    break;  

    case wDoubleTab:
      if (record->event.pressed) 
      {
        register_code(KC_LALT); 
        _delay_ms(100);    
        tap_code(KC_TAB);
        _delay_ms(100);    
        tap_code(KC_TAB);
        _delay_ms(100);    
        unregister_code(KC_LALT);
        return false;
      }
    break;  

    case wPWa0:
      if (record->event.pressed) 
      {
        register_code(KC_LSFT); 
        tap_code(KC_C);           
        unregister_code(KC_LSFT); 
        _delay_ms(100);  

        tap_code(KC_G);           
        tap_code(KC_T);           
        tap_code(KC_S);
        tap_code(KC_I);
        tap_code(KC_R);           
        tap_code(KC_E);           
        tap_code(KC_N);           

        // Ende
        tap_code(KC_0);           
        tap_code(KC_7);           

        // Fragezeichen "?"
        register_code(KC_LSFT);
        tap_code(KC_MINS);       
        unregister_code(KC_LSFT);
        _delay_ms(100);  

        // Ausrufezeichen "!"
        register_code(KC_LSFT); 
        tap_code(KC_1);           
        unregister_code(KC_LSFT); 
        _delay_ms(100);  
        tap_code(KC_ENT);  
        return false;
      }
    break; 

    case wPWa1:
      if (record->event.pressed) 
      {
        register_code(KC_LSFT); 
        tap_code(KC_C);           
        unregister_code(KC_LSFT); 
        _delay_ms(100);  

        tap_code(KC_G);           
        tap_code(KC_T);           
        tap_code(KC_S);
        tap_code(KC_I);
        tap_code(KC_R);           
        tap_code(KC_E);           
        tap_code(KC_N);           

        // Ende
        tap_code(KC_0);           
        tap_code(KC_7);           

        // Fragezeichen "?"
        register_code(KC_LSFT);
        tap_code(KC_MINS);       
        unregister_code(KC_LSFT);
        _delay_ms(100);  

        // Ausrufezeichen "!"
        register_code(KC_LSFT); 
        tap_code(KC_1);           
        unregister_code(KC_LSFT); 
        _delay_ms(100);   
        return false;
      }
    break; 

    case wPWa2:
      if (record->event.pressed) 
      {
        tap_code(KC_P);           
        tap_code(KC_R);           
        tap_code(KC_E);
        tap_code(KC_T);
        tap_code(KC_3);           
        tap_code(KC_2);           
        tap_code(KC_K);           
        tap_code(KC_X);     
        return false;
      }

    case wPWa3:
      if (record->event.pressed) 
      {
        register_code(KC_LSFT); 
        tap_code(KC_D);           
        unregister_code(KC_LSFT); 

        tap_code(KC_O);           
        tap_code(KC_R);
        tap_code(KC_I);
        tap_code(KC_A);           
        tap_code(KC_N);           
        tap_code(KC_D);           
        tap_code(KC_E);           
        tap_code(KC_R);   
        tap_code(KC_B);   
        tap_code(KC_O);   
        tap_code(KC_S);   
        tap_code(KC_S);           
        tap_code(KC_1);   
        tap_code(KC_0);   
        tap_code(KC_0);   

       // Ausrufezeichen "!"
        register_code(KC_LSFT); 
        tap_code(KC_1);           
        unregister_code(KC_LSFT); 
        _delay_ms(100);     
        return false;
      }

    case wPWa4:
      if (record->event.pressed) 
      {
        tap_code(KC_0);           
        tap_code(KC_7);           
        tap_code(KC_0);
        tap_code(KC_9);
        tap_code(KC_0);           
        tap_code(KC_7);              
        return false;
      }


    case wEm0:
      if (record->event.pressed) 
      {
        tap_code(KC_T);           
        tap_code(KC_F);           
        tap_code(KC_E);
        tap_code(KC_I);
        tap_code(KC_G);           
        tap_code(KC_E);           

        tap_code(KC_0);           
        tap_code(KC_4);           
        tap_code(KC_0);           
        tap_code(KC_6);   
      
        return false;
      }

    case wEm1:
      if (record->event.pressed) 
      {
        tap_code(KC_T);           
        tap_code(KC_F);           
        tap_code(KC_E);
        tap_code(KC_I);
        tap_code(KC_G);           
        tap_code(KC_E);           

        tap_code(KC_0);           
        tap_code(KC_4);           
        tap_code(KC_0);           
        tap_code(KC_6);   

        // At Zeichen
        register_code(KC_RALT);
        tap_code(KC_Q);       
        unregister_code(KC_RALT);
        _delay_ms(100);  
        
        tap_code(KC_M);
        tap_code(KC_A);           
        tap_code(KC_I);   
        tap_code(KC_L);   
        tap_code(KC_B);   
        tap_code(KC_O);   
        tap_code(KC_X);

        tap_code(KC_DOT);   

        tap_code(KC_O);   
        tap_code(KC_R);   
        tap_code(KC_G);   
      
        return false;
      }

    case wEm2:
      if (record->event.pressed) 
      {
        tap_code(KC_T);           
        tap_code(KC_F);           
        tap_code(KC_E);
        tap_code(KC_I);
        tap_code(KC_G);           
        tap_code(KC_E);           

        tap_code(KC_0);           
        tap_code(KC_4);           
        tap_code(KC_0);           
        tap_code(KC_6);   

        // At Zeichen
        register_code(KC_RALT);
        tap_code(KC_Q);       
        unregister_code(KC_RALT);
        _delay_ms(100);  
        
        tap_code(KC_I);
        tap_code(KC_C);           
        tap_code(KC_L);   
        tap_code(KC_O);   
        tap_code(KC_U);   
        tap_code(KC_D);   

        tap_code(KC_DOT);   

        tap_code(KC_C);   
        tap_code(KC_O);   
        tap_code(KC_M);   
      
        return false;
      }

    break; 

    case wEm3:
      if (record->event.pressed) 
      {
        tap_code(KC_T);           
        tap_code(KC_F);           
        tap_code(KC_E);
        tap_code(KC_I);
        tap_code(KC_G);           
        tap_code(KC_E);           

        tap_code(KC_1);           
        tap_code(KC_2);           
        tap_code(KC_3);           

        // At Zeichen
        register_code(KC_RALT);
        tap_code(KC_Q);       
        unregister_code(KC_RALT);
        _delay_ms(100);  
        
        tap_code(KC_G);
        tap_code(KC_M);           
        tap_code(KC_A);   
        tap_code(KC_I);   
        tap_code(KC_L);   

        tap_code(KC_DOT);   

        tap_code(KC_C);   
        tap_code(KC_O);   
        tap_code(KC_M);   
      
        return false;
      }

    case wEm4:
      if (record->event.pressed) 
      {
        tap_code(KC_T);           
        tap_code(KC_F);           
        tap_code(KC_E);
        tap_code(KC_I);
        tap_code(KC_G);           
        tap_code(KC_E);           

        tap_code(KC_0);           
        tap_code(KC_4);           
        tap_code(KC_0);           
        tap_code(KC_6);           

        // At Zeichen
        register_code(KC_RALT);
        tap_code(KC_Q);       
        unregister_code(KC_RALT);
        _delay_ms(100);  
        
        tap_code(KC_A);
        tap_code(KC_O);           
        tap_code(KC_L);   
      
        tap_code(KC_DOT);   

        tap_code(KC_C);   
        tap_code(KC_O);   
        tap_code(KC_M);   
      
        return false;
      }

    break; 

  }
  return true; 


};


