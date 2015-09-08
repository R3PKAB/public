<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>アンケート</title>
</head>
<body>
■アンケート結果
<br>
<table border=1>
<tr bgcolor="#CCCCCC">
<td>日付</td>
<td>性別</td>
<td>露店A</td>
<td>露店B</td>
<td>露店C</td>
<td>露店D</td>
<td>露店E</td>
<td>要望</td>
</tr>
<?php
	// ファイル名
	$filename = 'uploads/question.csv';

	// ロケール設定
	setlocale(LC_ALL, 'ja_JP');

	// readモードで開く
	$fh = fopen($filename,'r');

	// csvデータを取り出す
	while($data = fgetcsv($fh,1000)) {
		// 一行分のデータを取り出す
		list($date,$sex,$shop[0],$shop[1],$shop[2],$shop[3],$shop[4],$message) = $data;

		// 一行分のデータを表示
		echo '<tr>';
		echo '<td>' . $date .'</td>';
		echo '<td>' . $sex .'</td>';

		for ($i=0; $i<5; $i++) {
			if ($shop[$i] == '') {
				echo '<td>0</td>';
				//echo '<td align="center">－</td>';
			} else {
				echo '<td>1</td>';
				//echo '<td align="center">○</td>';
			}
		}
		echo '<td>' . $message .'</td>';
		echo '</tr>';

	}

	// 閉じる
	fclose($fh);
?>
</table>
</body>
</html>