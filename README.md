# public

##コード公開用

  pictフォルダ - 元画像(stationery.bmp/text.bmp)をフィルタリングやしきい値処理の画像処理を用いて処理画像(borde.bmp/fileter.bmp)として出力する
  border.c - モード法, 判別分析法, 移動平均法 (元画像はサンプル以外を用いる場合グレイ化する必要がある)

  filter.c - 平均化フィルタ, 加重平均化フィルタ, メディアンフィルタ, ピューウィットフィルタ, ソーベルフィルタ, 二次微分, 鮮鋭化
	
  result_sampleフォルダにそれぞれの処理後の結果がある

  lab_quest.c - 2分木を用いたyes/noゲーム(fnct研究室当て)

  fnct_fesフォルダ - fnctの学校祭に向けられて作られた各露店の人気と要望を調べるためのアンケート保存形式はcsvでデータベースには対応していない
	
  URLからshow_question.phpを指定するとcsvファイルのチェックができるのはデフォルト

  R3P_healthフォルダ - BMI計測,判定プログラム