/* syntax version 1 */
/* postgres can not */
PRAGMA EmitAggApply;

SELECT
    count(1 / 0)
FROM (
    VALUES
        (1),
        (NULL),
        (3)
) AS a (
    key
);
