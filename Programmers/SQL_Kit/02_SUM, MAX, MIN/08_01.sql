SELECT FISH_INFO.ID, FISH_NAME_INFO.FISH_NAME, FISH_INFO.LENGTH
FROM FISH_INFO
INNER JOIN FISH_NAME_INFO
ON FISH_INFO.FISH_TYPE = FISH_NAME_INFO.FISH_TYPE
WHERE (FISH_INFO.FISH_TYPE, FISH_INFO.LENGTH) IN (
                                                  SELECT FISH_TYPE, MAX(LENGTH)
                                                  FROM FISH_INFO
                                                  GROUP BY FISH_TYPE
                                                 )
ORDER BY FISH_INFO.ID;

-- 여러 개의 속성을 괄호로 묶어서 통째로 조건을 비교할 수 있다
-- WHERE(속성1, 속성2) IN (속성1 값, 속성2 값)