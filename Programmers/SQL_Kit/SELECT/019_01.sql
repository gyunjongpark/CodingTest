SELECT NAME
FROM ANIMAL_INS
WHERE DATETIME = (
                  SELECT MIN(DATETIME)
                  FROM ANIMAL_INS
                 );