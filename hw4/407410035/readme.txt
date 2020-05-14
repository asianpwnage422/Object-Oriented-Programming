學號：407410035
姓名：邱靖容
環境：csie2
E-mail：raisemmina@gmail.com
簡介：

Part A : Polygon
class:
　1.constructor
　2.destructor
　3.copy constructor
　4.getValue : 取得第 m 個點中第 n 維的值
　5.setValue : 設定第 m 個點中第 n 維的值
　6.FindCentroid : 給出多邊形的「重心」座標
　7.getNumOfPoints()：取得m值 （幾個點）
　8.getDimension()：取得n值 （維度多少）

Part B : Polynomial
利用linked-list
class :
　1.constructor : 利用add形成降冪
　2.destructor 
　3.add :
	若head->next不存在，head->next為new node（
	若存在：
		如果新項的exponent大於最高次，建立new node，將最高次接在新項後面。
		如果新項的exponent等於其中一項的exponent，將coef加起來。
	
　4.derivative（微分）:
	exponent*coef為新的chef
	exponen-1為新的exponen 
　5.show：印出polynomial
