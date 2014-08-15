#include <pebble.h>
#include <stdio.h>
#include "spain.h"
	
	
// para controlar el parpadeo de los segundos
int pulso =1;

// para iniciar el reloj, aunque no haya transcurrido un segundo, la primera vez
int inicializacion = 1;
int iniciaHora= 1;

// para cambiar el idioma de los literales de meses y días uso un índice
int idioma = 0;


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
static TextLayer *TLBateria;

static GBitmap *bateria_png;
static GBitmap *bl_png;

static void initialise_ui(void) {
    
  s_res_roboto_bold_subset_49 = fonts_get_system_font(FONT_KEY_ROBOTO_BOLD_SUBSET_49);
  s_res_bitham_30_black = fonts_get_system_font(FONT_KEY_BITHAM_30_BLACK);
  s_res_bitham_42_light = fonts_get_system_font(FONT_KEY_BITHAM_42_LIGHT);

	
  // BLesqSI
  BLesqSI = bitmap_layer_create(GRect(0, 0, 72, 84));
  bitmap_layer_set_background_color(BLesqSI, GColorWhite);
  layer_add_child(window_get_root_layer(s_window), (Layer *)BLesqSI);
  
  // BLesqSD
  BLesqSD = bitmap_layer_create(GRect(70, 0, 73, 84));
  bitmap_layer_set_background_color(BLesqSD, GColorBlack);
  layer_add_child(window_get_root_layer(s_window), (Layer *)BLesqSD);
  
  // BLesqII
  BLesqII = bitmap_layer_create(GRect(0, 84, 73, 84));
  bitmap_layer_set_background_color(BLesqII, GColorBlack);
  layer_add_child(window_get_root_layer(s_window), (Layer *)BLesqII);
  
  // BLesqID
  BLesqID = bitmap_layer_create(GRect(76, 84, 72, 84));
  layer_add_child(window_get_root_layer(s_window), (Layer *)BLesqID);
  
  // TLHora
  TLHora = text_layer_create(GRect(7, 10, 58, 64));
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
  TLDiaSem = text_layer_create(GRect(0, 92, 68, 50));
  text_layer_set_background_color(TLDiaSem, GColorClear);
  text_layer_set_text_color(TLDiaSem, GColorWhite);
  text_layer_set_text(TLDiaSem, "dom");
  text_layer_set_text_alignment(TLDiaSem, GTextAlignmentCenter);
  text_layer_set_font(TLDiaSem, s_res_bitham_30_black);
  layer_add_child(window_get_root_layer(s_window), (Layer *)TLDiaSem);
  
  // TLDia
  TLDia = text_layer_create(GRect(80, 82, 60, 46));
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
  TLPuntN = text_layer_create(GRect(61, 10, 16, 56));
  text_layer_set_background_color(TLPuntN, GColorClear);
  text_layer_set_text(TLPuntN, ":");
  text_layer_set_text_alignment(TLPuntN, GTextAlignmentCenter);
  text_layer_set_font(TLPuntN, s_res_roboto_bold_subset_49);
  layer_add_child(window_get_root_layer(s_window), (Layer *)TLPuntN);
  
  // TLPuntB
  TLPuntB = text_layer_create(GRect(71, 10, 14, 56));
  text_layer_set_background_color(TLPuntB, GColorClear);
  text_layer_set_text_color(TLPuntB, GColorWhite);
  text_layer_set_text(TLPuntB, ":");
  text_layer_set_text_alignment(TLPuntB, GTextAlignmentCenter);
  text_layer_set_font(TLPuntB, s_res_roboto_bold_subset_49);
  layer_add_child(window_get_root_layer(s_window), (Layer *)TLPuntB);
  
  // BLBat
  BLBat = bitmap_layer_create(GRect(15, 141, 55, 21));	
  bitmap_layer_set_bitmap(BLBat, gbitmap_create_with_resource(RESOURCE_ID_BATERIA_BLACK));
  layer_add_child(window_get_root_layer(s_window), (Layer *)BLBat);
	
  
  // BLBlut
  BLBlut = bitmap_layer_create(GRect(0, 141, 12, 21));
  layer_add_child(window_get_root_layer(s_window), (Layer *)BLBlut);
  
  // TLBateria
  TLBateria = text_layer_create(GRect(20, 142, 30, 18));
  text_layer_set_background_color(TLBateria, GColorClear);
  text_layer_set_text_color(TLBateria, GColorWhite);
  text_layer_set_text(TLBateria, "100");
  text_layer_set_text_alignment(TLBateria, GTextAlignmentCenter);
  layer_add_child(window_get_root_layer(s_window), (Layer *)TLBateria);
	
}

void select_click_handler(ClickRecognizerRef recognizer, void *context)
{
	idioma = idioma+1;
	if (idioma>1) {
		idioma = 0;
	}
}

void click_config_provider(void *context)
{
    window_single_click_subscribe(BUTTON_ID_SELECT, select_click_handler);
}

static void sustituye_imagen(GBitmap **imagen, BitmapLayer *bmp_layer, const int resource_id, GPoint origen) {
    GBitmap *vieja_imagen = *imagen;
    *imagen = gbitmap_create_with_resource(resource_id);
    GRect frame = (GRect) {
        .origin = origen,
        .size = (*imagen)->bounds.size
    };
    bitmap_layer_set_bitmap(bmp_layer, *imagen);
    layer_set_frame(bitmap_layer_get_layer(bmp_layer), frame);
    gbitmap_destroy(vieja_imagen);
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
  text_layer_destroy(TLBateria);
}
// END AUTO-GENERATED UI CODE

static void handle_bluetooth(bool connected)
{
	GRect frame = layer_get_frame((Layer *) BLBlut);
	GPoint pos = {frame.origin.x, frame.origin.y};
	const VibePattern pattern = {
  			.durations = (uint32_t []) {100, 300, 300, 300, 100, 300},
  			.num_segments = 6
	};
	
	if(connected == false)
	{
		sustituye_imagen(&bl_png, BLBlut, RESOURCE_ID_BLDESC_BLACK, pos);
		vibes_enqueue_custom_pattern(pattern);
	} else {
		sustituye_imagen(&bl_png, BLBlut, RESOURCE_ID_BL_BLACK, pos);
	}
}

static void handle_battery(BatteryChargeState estado) {
	GRect frame = layer_get_frame((Layer *) BLBat);
	GPoint pos = {frame.origin.x, frame.origin.y};
	
	if (estado.is_charging) {
		sustituye_imagen(&bateria_png, BLBat, RESOURCE_ID_CARGANDO_BLACK, pos);
	} else if (estado.is_plugged) {
		sustituye_imagen(&bateria_png, BLBat, RESOURCE_ID_CARGANDO_BLACK, pos);
	} else {
		sustituye_imagen(&bateria_png, BLBat, RESOURCE_ID_BATERIA_BLACK, pos);
	}
	static char buffer_b[] = "100 ";
	snprintf(buffer_b, sizeof(buffer_b), "%d", estado.charge_percent);
	text_layer_set_text(TLBateria, buffer_b);	
}

void handle_time(struct tm *tick_time, TimeUnits units_changed)
{
	if (units_changed & SECOND_UNIT) {
		//cambios producidos cada segundo
		if (pulso == 1) {
			text_layer_set_text(TLPuntB, " ");
			text_layer_set_text(TLPuntN, " ");
			pulso = 0;
		} else {
			text_layer_set_text(TLPuntB, ":");
			text_layer_set_text(TLPuntN, ":");
			pulso = 1;
		}		
	}

	if (units_changed & MINUTE_UNIT || inicializacion == 1) {
		// Cambios producidos cada minuto
		inicializacion = 0;
		
		static char buffer_dia[] = "00";
		static char buffer_hora[] = "00";
		static char buffer_min[] = "00";
		static char txt_dia[] = "dom ";
		static char txt_mes[] = "ene ";  
		int dia = tick_time->tm_wday;
		int mes = tick_time->tm_mon;

		strncpy(txt_dia, dias[7*idioma+dia], sizeof(dias[7*idioma+dia]));
		text_layer_set_text(TLDiaSem, txt_dia);

		strncpy(txt_mes, meses[12*idioma+mes], sizeof(meses[12*idioma+mes]));	  
		text_layer_set_text(TLMes, txt_mes);

		strftime(buffer_dia,sizeof("00"),"%d",tick_time);
		text_layer_set_text(TLDia,buffer_dia);

		strftime(buffer_hora,sizeof("00"),"%H",tick_time);
		text_layer_set_text(TLHora,buffer_hora);

		strftime(buffer_min,sizeof("00"),"%M",tick_time);
		text_layer_set_text(TLMinuto,buffer_min);
		
		handle_battery(battery_state_service_peek());
	}
if (units_changed & HOUR_UNIT  || iniciaHora == 1) {
    iniciaHora = 0;

}
}



void window_load(Window *window)
{
	initialise_ui();
	//Para la primera vez, lanzo manualmente la actualización del reloj y bluetooth
	time_t temp = time(NULL);
	handle_time(localtime(&temp), SECOND_UNIT);
	handle_battery(battery_state_service_peek());
	handle_bluetooth(bluetooth_connection_service_peek());

}

void window_unload(Window* window) {
	gbitmap_destroy(bateria_png);
	gbitmap_destroy(bl_png);
  	destroy_ui();
}

void init() {
	
	tick_timer_service_subscribe(SECOND_UNIT, &handle_time);
	bluetooth_connection_service_subscribe(&handle_bluetooth);
	battery_state_service_subscribe(&handle_battery);
	
	
	s_window = window_create();
	window_set_click_config_provider(s_window, click_config_provider);
	
	window_set_window_handlers(s_window, (WindowHandlers) {
		.load = window_load,
		.unload = window_unload,
	});

	window_stack_push(s_window,true);
}	


void deinit() {
	tick_timer_service_unsubscribe();
	bluetooth_connection_service_unsubscribe();
	battery_state_service_unsubscribe();
  	//window_destroy(s_window);
}

int main(void) {
    init();
    app_event_loop();
	deinit();
}
