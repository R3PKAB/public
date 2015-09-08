<html>
<head>
	<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
	<title>アンケート</title>
</head>
<?php
	error_reporting(E_ALL & ~E_NOTICE);
	//日付
	$date = htmlspecialchars($_POST['hdate'], ENT_QUOTES);
	echo $date;
	//性別
	$sex = htmlspecialchars($_POST['hsex'], ENT_QUOTES);
	//気に入った露店
	for( $i=0; $i < 5; $i++){
		if(isset($_POST['hshop'][$i])){
			$shop[$i] = htmlspecialchars($_POST['hshop'][$i], ENT_QUOTES);
		}
	}
	//要望
	$message = htmlspecialchars($_POST['hmessage'], ENT_QUOTES);
	//1つの配列にまとめる(保存データ)
	$data = array($date,$sex,$shop[0],$shop[1],$shop[2],$shop[3],$shop[4],$message);
	//保存ファイル名
	$filename = 'uploads/question.csv';
	//追記モードで開く
	$fh = fopen($filename,'a');
	//排他的ロック
	flock($fh, LOCK_EX);
	//csv書き込み
	fputcsv($fh,$data);
	//閉じる
	fclose($fh);

?>
■アンケートを登録しました。
<br><br>
</body>
</html>
