测试笛卡尔空间直线
函数：
	Cartesian_Line(Posi_Pose PP0, Posi_Pose PPf,  enum P2Pmethod cht = halfcos, enum TIMEorSPEED method = speed, double tf_lspeedp = 0.1,  double acce_p = 0.8, double t_interval_ = 0.01);

输入：	两个位姿 PP0 PPf， 曲线类型cht={ cubic, halfcos, trapez }，运行模式method={speed，time}
		运行参数tf_lspeedp 速度百分比或时间秒。非必需输入最大加速度百分比acce_p和插值周期t_interval。
		
输出：每周期插值数据，三个excel文件，
Line1_pose 姿态，四元数表示
Line1_posi 位置，三维
Line1_VA   速度，线速度和角速度，6维
	