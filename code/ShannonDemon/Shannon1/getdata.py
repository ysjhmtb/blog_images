import pandas as pd
import re

def getDataFromNaver(code):
    url = 'http://finance.naver.com/item/sise_day.nhn?code='+str(code)

    # 일자 데이터를 담을 df라는 DataFrame 정의
    df = pd.DataFrame()
    pattern = re.compile(r'\s+')

    # 1페이지에서 ?페이지의 데이터만 가져오기
    for page in range(1, 14):
        pg_url = '{url}&page={page}'.format(url=url, page=page)
        pg_url = re.sub(pattern, '', pg_url)
        df = df.append(pd.read_html(pg_url, header=0)[0], ignore_index=True)

    # df.dropna()를 이용해 결측값 있는 행 제거
    df = df.dropna()

    # 한글로 된 컬럼명을 영어로 바꿔줌
    df = df.rename(
        columns={'날짜': 'date', '종가': 'close', '전일비': 'diff', '시가': 'open', '고가': 'high', '저가': 'low', '거래량': 'volume'})

    # 데이터의 타입을 int형으로 바꿔줌
    df[['close', 'diff', 'open', 'high', 'low', 'volume']] \
        = df[['close', 'diff', 'open', 'high', 'low', 'volume']].astype(int)

    # 컬럼명 'date'의 타입을 date로 바꿔줌
    df['date'] = pd.to_datetime(df['date'])

    # 정렬 순서와 인덱스를 변경
    df = df.loc[::-1].reset_index(drop=True)

    return df

# 신한 S&P500 VIX S/T 선물 ETN B 500045
# print(getDataFromNaver(500045).head())

# KODEX 레버리지 122630
# print(getDataFromNaver(122630).head())

