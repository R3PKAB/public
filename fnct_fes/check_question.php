<html>
<head>
	<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
	<tutle>確認画面</title>
</head>
<?php
	
	//日付
	$date = htmlspecialchars($_POST['date'], ENT_QUOTES);
	//性別
	$sex = htmlspecialchars($_POST['sex'], ENT_QUOTES);
	//気に入った露店
	for($i=0; $i<5; $i++){
		if(isset($_POST['shop'][$i])){
			$shop[$i] = htmlspecialchars($_POST['shop'][$i], ENT_QUOTES);
			
		}

	}
	//要望
	$message = htmlspecialchars($_POST['message'], ENT_QUOTES);
?>
<body>
■アンケート内容を確認して下さい
<br><br>
高専祭に来た日付を教えて下さい<br>
<?php  echo $date;	?>
<br><br>
性別を教えて下さい<br>
<?php  echo $sex; ?>
<br><br>
気に入った露店(3つ)
<?php
	for($i=0; $i < 5; $i++){
		//チェックしているもののみ表示
		if(isset($shop[$i])) echo ' ['. $shop[$i] .'] ';
	}
?>
<br><br>
高専祭について要望があれば教えて下さい<br>
<?php
	//改行部分に<br>を埋め込む
	echo nl2br('「' . $_POST['message'] . '」');
?>
<br><br>
<form action="write_question.php" method="POST">
	<input type="hidden" name="hdate" value="<?php echo $date; ?>">
	<input type="hidden" name="hsex" value="<?php echo $sex; ?>">
	<?php
		for($i=0; $i < 5; $i++){
			if(isset($shop[$i])){
				echo '<input type="hidden" name="hshop['. $i. ']" value="' . $shop[$i] . '">';
			}
		}
	?>
	<input type="hidden" name="hmessage" value="<?php echo $message; ?>">
	<input type="submit" value="アンケートを送信する">
</form>
</body>
</html>