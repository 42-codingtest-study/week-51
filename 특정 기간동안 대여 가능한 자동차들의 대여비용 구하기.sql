# -- 코드를 입력하세요
SELECT      c.CAR_ID, c.CAR_TYPE, ROUND(c.DAILY_FEE * 30 * (1 - 0.01 * d.DISCOUNT_RATE)) as FEE
FROM        CAR_RENTAL_COMPANY_CAR c 
    JOIN CAR_RENTAL_COMPANY_DISCOUNT_PLAN d ON c.CAR_TYPE = d.CAR_TYPE
WHERE       (c.car_type = "세단" OR c.car_type="SUV")
            AND d.DURATION_TYPE = "30일 이상"
            AND NOT EXISTS (
                SELECT  *
                FROM    CAR_RENTAL_COMPANY_RENTAL_HISTORY h
                WHERE   c.CAR_ID = h.CAR_ID 
                    AND (
                        h.START_DATE BETWEEN '2022-11-01' AND '2022-11-30'
                        OR h.END_DATE BETWEEN '2022-11-01' AND '2022-11-30'
                        OR (START_DATE <= '2022-11-01' AND END_DATE >= '2022-11-30')
                    )
            )
HAVING      (500000 <= FEE AND FEE < 2000000)
ORDER BY    FEE DESC, c.CAR_TYPE ASC, c.CAR_ID DESC