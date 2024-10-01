-- 재귀적인 테이블 PARENT 생성
WITH RECURSIVE PARENT AS (
                          -- 반복되지 않는 초기 구문에서 새로운 속성 GENERATION 선언
                          SELECT ID, PARENT_ID, 1 AS GENERATION -- 초기 세대 값을 1로 설정
                          FROM ECOLI_DATA
                          WHERE PARENT_ID IS NULL

                          UNION -- 중복을 포함하지 않는 합집합

                          -- 위 구문을 기반으로 실시간으로 행을 받아 GENERATION을 1씩 추가하면서 생성
                          SELECT CHILD.ID, CHILD.PARENT_ID, PARENT.GENERATION + 1 AS GENERATION
                          FROM ECOLI_DATA AS CHILD, PARENT
                          WHERE PARENT.ID = CHILD.PARENT_ID
)
SELECT COUNT(ID) AS COUNT, GENERATION
FROM PARENT -- 위 재귀 테이블을 기반으로 결과 테이블 생성
WHERE ID NOT IN ( -- PARENT_ID에 존재하지 않는 ID만 추출(멸종 위기의 대장균 ID만 추출)
                 SELECT IFNULL(PARENT_ID, 0) AS PARENT_ID -- NULL은 연산 시 값이 부정확해질 수 있으므로 IFNULL 처리(NULL -> 0)
                 FROM ECOLI_DATA
                )
GROUP BY GENERATION
ORDER BY GENERATION;
