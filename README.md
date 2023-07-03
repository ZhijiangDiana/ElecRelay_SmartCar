# 主电磁代码

可以在`config.h`文件中进行一些配置，如：
- 指定车辆类别
- 电机调试模式，可以通过蓝牙在上位机虚拟示波器中显示左右轮数据
- 舵机调试模式，可以通过蓝牙在上位机虚拟示波器中显示舵机偏差

## 电机调试模式说明：

- 从正看屏幕方向，屏幕右边自上到下四个按键分别为1,2,3,4
- 按键123指代速度低中高（小车10/30/50，大车25/45/65）三挡

## pid调试相关
- 电机pid在`motor.c`的`PID_param_init()`函数内，注意需要同时调左右轮，一般情况下两个轮一样的pid就行。理论上只调pi就可以得到目标效果。先调p再i最后d，参数数量级参考：`kp0.06,ki0.000038`
- 舵机pid是`servo.c`的`elec_Kp`函数，只需要调pd，参数数量级参考：`kp15,kd0.9`