#include "main_window.h"
#include <pebble.h>
#include <stdio.h>
	
static TextLayer *TLBateria;

static const char *dias[] = {
  "Dom", "Lun", "Mar", "Mié", "Jue", "Vie", "Sáb"
};

static const char *meses[] = {
  "ene", "feb", "mar", "abr", "may", "jun", 
  "jul", "ago", "sep", "oct", "nov", "dic"
};  
	

// BEGIN AUTO-GENERATED UI CODE; DO NOT MODIFY
static Window *s_window;
static GFont s_res_roboto_bold_subset_49;
static GFont s_res_bitham_30_black;
static GFont s_res_bitham_42_light;
static BitmapLayer *BLesqSI;
static BitmapLayer *BLesqSD;
static BitmapLayer *BLesqII;
static BitmapLayer *BLesqID;
static TextLayer *TLHora;
static TextLayer *TLMinuto;
static TextLayer *TLDiaSem;
static TextLayer *TLDia;
static TextLayer *TLMes;
static TextLayer *TLPuntN;
static TextLayer *TLPuntB;
static BitmapLayer *BLBat;
static BitmapLayer *BLBlut;

static void initialise_ui(void) {
  s_window = window_create();
  window_set_fullscreen(s_window, true);
  
  s_res_roboto_bold_subset_49 = fonts_get_system_font(FONT_KEY_ROBOTO_BOLD_SUBSET_49);
  s_res_bitham_30_black = fonts_get_system_font(FONT_KEY_BITHAM_30_BLACK);
  s_res_bitham_42_light = fonts_get_system_font(FONT_KEY_BITHAM_42_LIGHT);
  // BLesqSI
  BLesqSI = bitmap_layer_create(GRect(0, 0, 72, 84));
  bitmap_layer_set_background_color(BLesqSI, GColorWhite);
  layer_add_child(window_get_root_layer(s_window), (Layer *)BLesqSI);
  
  // BLesqSD
  BLesqSD = bitmap_layer_create(GRect(72, 0, 72, 84));
  bitmap_layer_set_background_color(BLesqSD, GColorBlack);
  layer_add_child(window_get_root_layer(s_window), (Layer *)BLesqSD);
  
  // BLesqII
  BLesqII = bitmap_layer_create(GRect(0, 84, 72, 84));
  bitmap_layer_set_background_color(BLesqII, GColorBlack);
  layer_add_child(window_get_root_layer(s_window), (Layer *)BLesqII);
  
  // BLesqID
  BLesqID = bitmap_layer_create(GRect(72, 84, 72, 84));
  layer_add_child(window_get_root_layer(s_window), (Layer *)BLesqID);
  
  // TLHora
  TLHora = text_layer_create(GRect(10, 10, 58, 64));
  text_layer_set_background_color(TLHora, GColorBlack);
  text_layer_set_text_color(TLHora, GColorWhite);
  text_layer_set_text(TLHora, "24");
  text_layer_set_text_alignment(TLHora, GTextAlignmentCenter);
  text_layer_set_font(TLHora, s_res_roboto_bold_subset_49);
  layer_add_child(window_get_root_layer(s_window), (Layer *)TLHora);
  
  // TLMinuto
  TLMinuto = text_layer_create(GRect(78, 10, 58, 64));
  text_layer_set_text(TLMinuto, "59");
  text_layer_set_text_alignment(TLMinuto, GTextAlignmentCenter);
  text_layer_set_font(TLMinuto, s_res_roboto_bold_subset_49);
  layer_add_child(window_get_root_layer(s_window), (Layer *)TLMinuto);
  
  // TLDiaSem
  TLDiaSem = text_layer_create(GRect(0, 106, 71, 40));
  text_layer_set_background_color(TLDiaSem, GColorClear);
  text_layer_set_text_color(TLDiaSem, GColorWhite);
  text_layer_set_text(TLDiaSem, "Dom");
  text_layer_set_text_alignment(TLDiaSem, GTextAlignmentCenter);
  text_layer_set_font(TLDiaSem, s_res_bitham_30_black);
  layer_add_child(window_get_root_layer(s_window), (Layer *)TLDiaSem);
  
  // TLDia
  TLDia = text_layer_create(GRect(77, 82, 60, 46));
  text_layer_set_background_color(TLDia, GColorClear);
  text_layer_set_text(TLDia, "30");
  text_layer_set_text_alignment(TLDia, GTextAlignmentCenter);
  text_layer_set_font(TLDia, s_res_bitham_42_light);
  layer_add_child(window_get_root_layer(s_window), (Layer *)TLDia);
  
  // TLMes
  TLMes = text_layer_create(GRect(74, 128, 66, 36));
  text_layer_set_background_color(TLMes, GColorBlack);
  text_layer_set_text_color(TLMes, GColorWhite);
  text_layer_set_text(TLMes, "may");
  text_layer_set_text_alignment(TLMes, GTextAlignmentCenter);
  text_layer_set_font(TLMes, s_res_bitham_30_black);
  layer_add_child(window_get_root_layer(s_window), (Layer *)TLMes);
  
  // TLPuntN
  TLPuntN = text_layer_create(GRect(63, 10, 12, 56));
  text_layer_set_background_color(TLPuntN, GColorClear);
  text_layer_set_text(TLPuntN, ":");
  text_layer_set_text_alignment(TLPuntN, GTextAlignmentCenter);
  text_layer_set_font(TLPuntN, s_res_roboto_bold_subset_49);
  layer_add_child(window_get_root_layer(s_window), (Layer *)TLPuntN);
  
  // TLPuntB
  TLPuntB = text_layer_create(GRect(69, 10, 9, 60));
  text_layer_set_background_color(TLPuntB, GColorClear);
  text_layer_set_text_color(TLPuntB, GColorWhite);
  text_layer_set_text(TLPuntB, ":");
  text_layer_set_text_alignment(TLPuntB, GTextAlignmentCenter);
  text_layer_set_font(TLPuntB, s_res_roboto_bold_subset_49);
  layer_add_child(window_get_root_layer(s_window), (Layer *)TLPuntB);
  
  // BLBat
  BLBat = bitmap_layer_create(GRect(17, 143, 38, 14));
  bitmap_layer_set_background_color(BLBat, GColorWhite);
  layer_add_child(window_get_root_layer(s_window), (Layer *)BLBat);
  
  // BLBlut
  BLBlut = bitmap_layer_create(GRect(20, 90, 34, 21));
  bitmap_layer_set_background_color(BLBlut, GColorWhite);
  layer_add_child(window_get_root_layer(s_window), (Layer *)BLBlut);
}

static void destroy_ui(void) {
  window_destroy(s_window);
  bitmap_layer_destroy(BLesqSI);
  bitmap_layer_destroy(BLesqSD);
  bitmap_layer_destroy(BLesqII);
  bitmap_layer_destroy(BLesqID);
  text_layer_destroy(TLHora);
  text_layer_destroy(TLMinuto);
  text_layer_destroy(TLDiaSem);
  text_layer_destroy(TLDia);
  text_layer_destroy(TLMes);
  text_layer_destroy(TLPuntN);
  text_layer_destroy(TLPuntB);
  bitmap_layer_destroy(BLBat);
  bitmap_layer_destroy(BLBlut);
}
// END AUTO-GENERATED UI CODE


void tick_handler(struct tm *tick_time, TimeUnits units_changed)
{
    
	//Control de la carga de la batería
	static char buffer_b[] = "100%";
	static char buffer_dia[] = "00";
	static char buffer_hora[] = "00";
	BatteryChargeState state = battery_state_service_peek();
	if (state.is_charging) {
		strcpy(buffer_b, "×××");
	} else {
		snprintf(buffer_b, sizeof("100%"), "%d%%", state.charge_percent);
	}
	text_layer_set_text(TLBateria, buffer_b);
	
	static char txt_dia[] = "DOM";
	static char txt_mes[] = "ENE";  
	int dia = tick_time->tm_wday;
	int mes = tick_time->tm_mon;

	strcpy(txt_dia, dias[dia]);
	text_layer_set_text(TLDiaSem, txt_dia);
	
	strcpy(txt_mes, meses[mes]);	  
	text_layer_set_text(TLMes, txt_mes);
	
	strftime(buffer_dia,sizeof("00"),"%d",tick_time);
	text_layer_set_text(TLDia,buffer_dia);
  
  	strftime(buffer_hora,sizeof("00"),"%H",tick_time);
	text_layer_set_text(TLHora,buffer_hora);
	
	strftime(buffer_hora,sizeof("00"),"%M",tick_time);
	text_layer_set_text(TLMinuto,buffer_hora);
}





void show_main_window(void) {
  	initialise_ui();
	
	struct tm *t;
	time_t temp;	
	temp = time(NULL);	
	t = localtime(&temp);	

	//Manually call the tick handler when the window is loading
	tick_handler(t, MINUTE_UNIT);
}	

static void handle_window_unload(Window* window) {
  	destroy_ui();
	text_layer_destroy(TLBateria);

	tick_timer_service_subscribe(MINUTE_UNIT, (TickHandler) tick_handler);
		window_set_window_handlers(s_window, (WindowHandlers) {
    	.unload = handle_window_unload,
  });
  window_stack_push(s_window, true);
}

void hide_main_window(void) {
	tick_timer_service_unsubscribe();
  	window_stack_remove(s_window, true);
}
