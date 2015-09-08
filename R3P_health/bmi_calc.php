<html>
	<head>
		<meta http-equiv="Content-Type" content="text/html; carset=UTF-8">
		<title>BMI計算機</title>
	</head>
	
	<body>
		体重と身長を入力してください<br>
		<form action="bmi_calc.php" method="POST">
			体重[kg]：<br>
			<input type="text" name="weight" size="4"><br>
			身長[m]：<br>
			<input type="text" name="haight" size="5"><br>
			<input type="submit" value="計算">
		</form>
	
		<?php
	
		$weight = $_POST["weight"];
		$haight = $_POST["haight"];
		
		if(10 < $haight) $haight = $haight / 100; 
		
		$bmi = $weight / (($haight*$haight));
		$weight_std = (($haight)*($haight)) * 22;
		

		echo "身長 : ".$haight."[m]<br>";
		echo "体重 : ".$weight."[kg]<br>";
		
		if(18.5 > $bmi){
			echo "判定：低体重(痩せ型)<br>";
		}
		else if(18.5 <= $bmi && 25 > $bmi){
			echo "判定：普通体重<br>";
		}
		else if(25 <= $bmi && 30 > $bmi){
			echo "判定：肥満(1度)<br>";
		}
		else if(30 <= $bmi && 35 > $bmi){
			echo "判定：肥満(2度)<br>";
		}
		else if(35 <= $bmi && 40 > $bmi){
			echo "判定：肥満(3度)<br>";
		}
		else if(40 <= $bmi){
			echo "判定：肥満(4度)<br>";
		}
		
		echo "BMI：".$bmi."<br>";
		echo "標準体重：[kg]".$weight_std."<br>";
		
		?>
	</body>
</html>