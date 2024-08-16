SELECT ITEM_INFO.ITEM_ID, ITEM_INFO.ITEM_NAME, ITEM_INFO.RARITY
FROM ITEM_INFO
WHERE ITEM_INFO.ITEM_ID IN (
    SELECT ITEM_TREE.ITEM_ID
    FROM ITEM_TREE WHERE ITEM_TREE.PARENT_ITEM_ID IN (
                            SELECT ITEM_ID
                            FROM ITEM_INFO
                            WHERE RARITY = 'RARE'
                        )
)
ORDER BY ITEM_INFO.ITEM_ID DESC;

/*
부속질의부터 천천히 접근하는 문제

1. rare인 아이템 id를 ITEM 테이블에서 찾는다
2. 해당 id가 TREE 테이블의 부모 id가 되고, 업그레이드 할 수 있는 id를 TREE에서 찾는다
3. 찾은 id를 다시 ITEM 테이블에서 조회한 후 최종 결과를 얻는다

*/
