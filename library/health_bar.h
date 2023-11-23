#ifndef Health_bar
#define Health_bar
#include"texture.h"
bool did_character1_get_hit=false;
//
Ltexture character1_face;
Ltexture health_bar_1_for_character1;
Ltexture health_bar_2_for_character1;
//
Ltexture character2_face;
Ltexture health_bar_1_for_character2;
Ltexture health_bar_2_for_character2;
//


  double health_bar_2_of_character1=400;
  int losing_health_of_ch1=0;
  double health_bar_2_of_character2=400;
  int losing_health_of_ch2=0;
  double tdx_health_bar_2_of_character2=1080-400;



Mix_Chunk *music_taken_dam=NULL;

#endif // texture
void reset_health_bar(int &tdx_of_losing_effect1,int &tdy_of_losing_effect1,bool &key_active_effect_of_losing_health1,
                      bool &key_active_effect_of_losing_health2,int &tdx_of_losing_effect2,int &tdy_of_losing_effect2){


      health_bar_2_of_character1=400;
      losing_health_of_ch1=0;
      health_bar_2_of_character2=400;
      losing_health_of_ch2=0;
      tdx_health_bar_2_of_character2=1080-400;


      tdx_of_losing_effect1=tdx_character1+5;
      tdy_of_losing_effect1=height_of_screen/4*3;
      key_active_effect_of_losing_health1=false;

      tdx_of_losing_effect2=tdx_character2+5;
      tdy_of_losing_effect2=height_of_screen/4*3;
      key_active_effect_of_losing_health2=false;

}

void free_music_taken_dam(){
     Mix_FreeChunk( music_taken_dam);
     music_taken_dam = NULL;

}

void set_music_taken_dam(){
    music_taken_dam=Mix_LoadWAV("music/taken_dam.mp3");
    if( music_taken_dam == NULL )
	{
		printf( "Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError() );

	}

}




       void set_health_bar_for_character1(double health_bar_2_of_character1, bool choose_skin1,bool choose_skin2){
        if(choose_skin1){
         character1_face.loadtexture("image/sans_face.bmp");
        }
        if(choose_skin2){
         character1_face.loadtexture("image/error_sans_face.bmp");
        }

         character1_face.settdx(0);
         character1_face.settdy(0);
         character1_face.setheight(120);
         character1_face.setwidth(128);

         health_bar_1_for_character1.setheight(120);
         health_bar_1_for_character1.setwidth(400);
         health_bar_1_for_character1.settdx(0);
         health_bar_1_for_character1.settdy(0);
         health_bar_1_for_character1.loadtexture("image/health_bar_1.bmp");

         health_bar_2_for_character1.setheight(120);
         health_bar_2_for_character1.setwidth(health_bar_2_of_character1);
         health_bar_2_for_character1.settdx(0);
         health_bar_2_for_character1.settdy(0);
         health_bar_2_for_character1.loadtexture("image/health_bar_2.bmp");

          health_bar_1_for_character1.render(NULL);
         health_bar_2_for_character1.render(NULL);
         character1_face.render(NULL);
      }

       void set_health_bar_for_character2(double health_bar_2_of_character2,double tdx_health_bar_2_of_character2){
         character2_face.loadtexture("image/chara_face.bmp");
         character2_face.settdx(1080-128);
         character2_face.settdy(0);
         character2_face.setheight(120);
         character2_face.setwidth(128);


         health_bar_1_for_character2.setheight(120);
         health_bar_1_for_character2.setwidth(400);
         health_bar_1_for_character2.settdx(1080-400);
         health_bar_1_for_character2.settdy(0);
         health_bar_1_for_character2.loadtexture("image/health_bar_1.bmp");

         health_bar_2_for_character2.setheight(120);
         health_bar_2_for_character2.setwidth(health_bar_2_of_character2);
         health_bar_2_for_character2.settdx(tdx_health_bar_2_of_character2);
         health_bar_2_for_character2.settdy(0);
         health_bar_2_for_character2.loadtexture("image/health_bar_2.bmp");

         health_bar_1_for_character2.render(NULL);
         health_bar_2_for_character2.render(NULL);
         character2_face.render(NULL);

      }



      Ltexture lose_health_1;
      int tdx_of_losing_effect1=0;
      int tdy_of_losing_effect1=0;
      bool key_active_effect_of_losing_health1=false;

      Ltexture lose_health_2;
      int tdx_of_losing_effect2=0;
      int tdy_of_losing_effect2=0;
      bool key_active_effect_of_losing_health2=false;


      void set_lose_health_1(){
           tdx_of_losing_effect1=tdx_character1+5;
           tdy_of_losing_effect1=height_of_screen/4*3;
           lose_health_1.loadtexture("image/health_effect_-1.bmp");
           lose_health_1.setheight(12);
           lose_health_1.setwidth(12);
           lose_health_1.settdx(tdx_of_losing_effect1);
           lose_health_1.settdy(tdy_of_losing_effect1);
      }
         void set_lose_health_2(){
           tdx_of_losing_effect2=tdx_character2+5;
           tdy_of_losing_effect2=height_of_screen/4*3;
           lose_health_2.loadtexture("image/health_effect_-1.bmp");
           lose_health_2.setheight(12);
           lose_health_2.setwidth(12);
           lose_health_2.settdx(tdx_of_losing_effect2);
           lose_health_2.settdy(tdy_of_losing_effect2);
      }




      void set_lose_health_1_appear(int x,int y){
          if(key_active_effect_of_losing_health1){
           tdx_of_losing_effect1=x+5;
           lose_health_1.setheight(36);
           lose_health_1.setwidth(36);
           lose_health_1.settdx(tdx_of_losing_effect1);
           lose_health_1.settdy(tdy_of_losing_effect1);
           lose_health_1.render(NULL);
           tdy_of_losing_effect1=tdy_of_losing_effect1-1;
          }
          else{
              tdy_of_losing_effect1=height_of_screen/4*3;
              tdx_of_losing_effect1=x+5;
          }

      }


       void set_lose_health_2_appear(int x,int y){
          if(key_active_effect_of_losing_health2){
           tdx_of_losing_effect2=x+5;
           lose_health_2.setheight(36);
           lose_health_2.setwidth(36);
           lose_health_2.settdx(tdx_of_losing_effect2);
           lose_health_2.settdy(tdy_of_losing_effect2);
           lose_health_2.render(NULL);
           tdy_of_losing_effect2=tdy_of_losing_effect2-1;
          }
          else{
              tdy_of_losing_effect2=height_of_screen/4*3;
              tdx_of_losing_effect2=x+5;
          }

      }

      void set_ch1_loses_health(double &mhealth_bar_2_of_character1,Ltexture mhealth_bar_2_for_character1,
                                int mlosing_health_of_ch1,bool &mkey_active_effect_of_losing_health1,
                                int x,int y,bool &mdid_character1_get_hit,bool stopping_time){
        if(!stopping_time){
           mhealth_bar_2_of_character1=mhealth_bar_2_of_character1-mlosing_health_of_ch1;
           mhealth_bar_2_for_character1.settdx(mhealth_bar_2_for_character1.gettdx()-mlosing_health_of_ch1);
           mkey_active_effect_of_losing_health1=true;
           set_lose_health_1_appear(x,y);
        }

      }


      void set_ch2_loses_health(double &mhealth_bar_2_of_character2,Ltexture mhealth_bar_2_for_character2,
                                int mlosing_health_of_ch2,bool &mkey_active_effect_of_losing_health2,
                                int x,int y,bool &mdid_character2_get_hit,double &mtdx_health_bar_2_of_character2,bool stopping_time){
           if(!stopping_time){
           mhealth_bar_2_of_character2=mhealth_bar_2_of_character2-mlosing_health_of_ch2;
           mtdx_health_bar_2_of_character2=mtdx_health_bar_2_of_character2+mlosing_health_of_ch2;
           mkey_active_effect_of_losing_health2=true;
           set_lose_health_2_appear(x,y);
           }

      }
