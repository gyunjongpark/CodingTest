SELECT ITEM_INFO.ITEM_ID, ITEM_INFO.ITEM_NAME, ITEM_INFO.RARITY
FROM ITEM_INFO
WHERE ITEM_INFO.ITEM_ID IN (
                            SELECT ITEM_TREE.ITEM_ID
                            FROM ITEM_TREE
                            WHERE ITEM_TREE.PARENT_ITEM_ID IN (
                                                              SELECT ITEM_ID
                                                              FROM ITEM_INFO
                                                              WHERE RARITY = 'RARE'
                                                              )
                           )
ORDER BY ITEM_INFO.ITEM_ID DESC;

/*
부속질의부터 천천히 접근하는 문제
1. rare 등급 아이템의 ITEM_ID를 ITEM_INFO 테이블에서 찾는다
2. INFO에서 찾은 ITEM_ID가 TREE 테이블의 PARENT_ITEM_ID인 ITEM_ID를 TREE 테이블에서 찾는다
3. TREE에서 찾은 ITEM_ID를 다시 ITEM 테이블에서 조회한 후 최종 결과를 얻는다
*/
