SELECT ROUND(AVG(DAILY_FEE),0) AS AVERAGE_FEE
FROM CAR_RENTAL_COMPANY_CAR
WHERE CAR_TYPE='SUV';

-- ROUND(속성의 집계함수, 자릿수 n)  소수 n 번째 자릿수까지 소수점 표현. 반올림 적용
-- ex) SELECT ROUND(42.195, 2) -> 42.20