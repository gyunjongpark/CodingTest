SELECT INFO.ITEM_ID, INFO.ITEM_NAME, INFO.RARITY
FROM ITEM_INFO INFO LEFT OUTER JOIN ITEM_TREE TREE
ON INFO.ITEM_ID = TREE.ITEM_ID
WHERE PARENT_ITEM_ID IN (
                         SELECT ITEM_ID
                         FROM ITEM_INFO
                         WHERE RARITY = 'RARE'
                        )
ORDER BY INFO.ITEM_ID DESC;

-- 외부 조인으로 두 테이블을 ITEM_ID로 묶어 합친 후 결과를 도출한다
