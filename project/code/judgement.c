/*
 * judgement.c
 *
 *  Created on: 2023年6月18日
 *      Author: 清梦
 */
#include "judgement.h"

RaceStatus CURRENT_STATUS = Status_Common;
RaceStatus CURRENT_MOTOR_STATUS = Status_Common;

uint8 out_garage_flag = false, in_garage_flag = false;
uint8 left_circle_flag=false, right_circle_flag=false, cross_flag=false, obstacle_flag=false, front_diuxian_flag=false, slope_flag=false;
#if CAR_TYPE
uint8 circle_threshold=40, cross_threshold=80;
#else
uint8 circle_threshold=40, cross_threshold=80;
#endif
uint8 circle_status=0;//环岛处理标志
bool out_flag = false;

uint16 cross_cnt = 0;
uint32 circle_cnt = 5000;

void judgement()
{

    //todo 114514
    if(!obstacle_flag && !in_garage_flag && !cross_flag && cross_cnt>=CROSS_DELAY_TIME && (adc_LL>cross_threshold && adc_RR>cross_threshold))
    {// 入十字判断
        cross_flag = true;
        cross_cnt%=CROSS_DELAY_TIME;
    }
    else if(!obstacle_flag && !in_garage_flag && cross_flag && cross_cnt>=CROSS_DELAY_TIME && (adc_LL>cross_threshold && adc_RR>cross_threshold))
    {// 出十字判断
        cross_flag = false;
        cross_cnt%=CROSS_DELAY_TIME;
    }
#if ENABLE_LOOP
    else if(!obstacle_flag && !in_garage_flag && !cross_flag && cross_cnt>=CROSS_DELAY_TIME && circle_cnt>=Circle_Delay_time && Angle<95 && adc_LL>circle_threshold && adc_RR<circle_threshold && yuansu_cnt==yuansu_cnt_enum[2])
    {// 左环岛判断
        left_circle_flag = true;
        circle_status = 1;
        cross_cnt = 0;
    }
    else if(!obstacle_flag && !in_garage_flag && !cross_flag && cross_cnt>=CROSS_DELAY_TIME && circle_cnt>=Circle_Delay_time && Angle>85 && adc_LL<circle_threshold && adc_RR>circle_threshold && yuansu_cnt==yuansu_cnt_enum[3])
    {// 右环岛判断
        right_circle_flag = true;
        circle_status = 1;
        cross_cnt = 0;
    }
#endif

    if(cross_cnt<=CROSS_DELAY_TIME)
        cross_cnt++;

    if(circle_cnt<=Circle_Delay_time)
        circle_cnt++;
}



















