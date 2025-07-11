# Ограничения базы данных

В  разделе описаны параметры ограничений, установленных в {{ ydb-short-name }}.

## Ограничения объектов схемы {#schema-object}

В таблице ниже приведены ограничения объектов схемы: таблиц, баз данных, столбцов. В столбце _Объект_ указан тип объекта схемы, на который распространяется ограничение.
В столбце _Тип ошибки_ указан статус, с которым завершится выполнение запроса в случае ошибки. Подробнее статусы описаны в разделе [Обработка ошибок в API](../../reference/ydb-sdk/error_handling.md).

| Объект | Ограничение | Значение | Пояснение | Внутреннее<br/>название | Тип<br/>ошибки |
| :--- | :--- | :--- | :--- | :---: | :---: |
| База данных | Максимальная глубина пути | 32 | Максимальное количество вложенных элементов пути (директорий, таблиц). | MaxDepth | SCHEME_ERROR |
| База данных | Максимальное количество путей (объектов в схеме) | 10 000 | Максимальное количество элементов пути (директорий, таблиц) в базе данных. | MaxPaths | GENERIC_ERROR |
| База данных | Максимальное количество таблеток | 200 000 | Максимальное количество таблеток (шардов таблиц и системных таблеток), которое может работать в базе данных. На запрос создания, копирования или изменения таблицы, в результате выполнения которого данное ограничение может быть превышено, будет возвращена ошибка. При достижении максимального количества таблеток в базе автоматическое шардирование таблиц не происходит. | MaxShards | GENERIC_ERROR |
| База данных | Максимальная длина имени объекта | 255 | Ограничивает количество символов в имени объекта схемы, например директории или таблицы. | MaxPathElementLength | SCHEME_ERROR |
| База данных | Максимальный размер ACL | 10 Кб | Максимальный суммарный размер всех правил контроля доступа, которые можно сохранить для одного объекта схемы. | MaxAclBytesSize | GENERIC_ERROR |
| Директория | Максимальное количество объектов | 100 000 | Максимальное количество таблиц, директорий, созданных в директории. | MaxChildrenInDir | SCHEME_ERROR |
| Таблица | Максимальное количество шардов таблицы  | 35 000 | Максимальное количество шардов таблицы. | MaxShardsInPath | GENERIC_ERROR |
| Таблица | Максимальное количество столбцов | 200 | Ограничивает общее количество столбцов в таблице. | MaxTableColumns | GENERIC_ERROR |
| Таблица | Максимальная длина имени столбца | 255 | Ограничивает количество символов в имени столбца.  | MaxTableColumnNameLength | GENERIC_ERROR |
| Таблица | Максимальное количество столбцов в первичном ключе | 20 | Каждая таблица должна иметь первичный ключ. Количество столбцов, входящих в состав первичного ключа, не может превышать это ограничение. | MaxTableKeyColumns | GENERIC_ERROR |
| Таблица | Максимальное количество индексов | 20 | Максимальное количество индексов помимо индекса первичного ключа, которые могут быть созданы на таблице. | MaxTableIndices | GENERIC_ERROR |
| Таблица | Максимальное количество фолловеров | 3 | Максимальное количество read-only реплик, которое можно указать при создании таблицы с фолловерами. | MaxFollowersCount | GENERIC_ERROR |
| Таблица | Максимальное количество копируемых таблиц | 10 000 | Ограничение на размер списка таблиц для операций консистентного копирования таблиц. | MaxConsistentCopyTargets | GENERIC_ERROR |

{wide-content}

## Ограничения размеров хранимых данных {#data-size}

| Параметр | Значение | Тип ошибки |
| :--- | :--- |  :---: |
| Максимальный суммарный размер всех столбцов в первичном ключе | 1 Мб | GENERIC_ERROR |
| Максимальный размер значения строкового столбца  | 16 Мб | GENERIC_ERROR |

## Ограничения аналитических таблиц

Параметр | Значение
:--- | :---
Максимальный размер строки | 8 Мб
Максимальный размер вставляемого блока данных | 8 Мб

## Ограничения при выполнении запросов {#query}

В таблице ниже перечислены ограничения, действующие при выполнении запросов.

| Параметр | Значение | Пояснение | Статус<br/>в случае<br/>нарушения<br/>ограничения |
| :--- | :--- | :--- | :---: |
| Длительность запроса | 1800 секунд (30 минут) | Максимальное время на выполнение одного запроса. | TIMEOUT |
| Максимальное количество сессий на ноду кластера  | 1000 | Ограничение на количество сессий, которые клиент может создать с каждой нодой {{ ydb-short-name }}. | OVERLOADED |
| Максимальная длина текста запроса | 10 Кб | Ограничение на длину текста YQL-запроса. | BAD_REQUEST |
| Максимальный размер значений параметров | 50 Мб | Ограничение на суммарный размер параметров, передаваемых при выполнении ранее подготовленного запроса. | BAD_REQUEST |
| Максимальный размер строки | 50 Мб | Ограничение на суммарный размер всех полей одной строки, возвращаемой или формируемой запросом. | PRECONDITION_FAILED |

{% cut "Устаревшие ограничения" %}

В предыдущих версиях {{ ydb-short-name }} запросы выполнялись с помощью API под названием «Table Service». Этот API имел следующие ограничения, которые были устранены при переходе на новый API под названием «Query Service».

#|
|| Параметр | Значение | Пояснение | Статус в случае нарушения ограничения ||
|| Максимальное количество строк в результате запроса
| 1000
| Полные результаты некоторых запросов, выполненных через метод `ExecuteDataQuery`, могут содержать больше строк, чем допустимо. В этом случае в ответ на запрос вернется максимально допустимое число строк, а у результата будет установлен флаг `truncated`.
| SUCCESS ||
|| Максимальный размер результата запроса
| 50 Мб
| Полный результат некоторых запросов может превышать установленное ограничение. В этом случае запрос завершится ошибкой, данные не будут возвращены.
| PRECONDITION_FAILED ||
|#

{% endcut %}

## Ограничения пулов ресурсов {#resource_pool}

| Параметр | Значение |
| :--- | :--- |
| Максимальное число классификаторов пулов ресурсов | 1000 |

Ограничения на число ресурсов накладываются ограничениями на число схемных объектов. Эти ограничения можно найти [выше](#schema-object).
