SELECT INFO.ITEM_ID, INFO.ITEM_NAME, INFO.RARITY
FROM ITEM_INFO INFO LEFT OUTER JOIN ITEM_TREE TREE
ON INFO.ITEM_ID = TREE.ITEM_ID
WHERE PARENT_ITEM_ID IN (
                            SELECT ITEM_ID
                            FROM ITEM_INFO
                            WHERE RARITY = 'RARE'
                        )
ORDER BY INFO.ITEM_ID DESC;