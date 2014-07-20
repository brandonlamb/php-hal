PHP_ARG_ENABLE(phal, whether to enable phal, [ --enable-phal   Enable Phal])

if test "$PHP_PHAL" = "yes"; then
	AC_DEFINE(HAVE_PHAL, 1, [Whether you have Phal])
	phal_sources="phal.c kernel/main.c kernel/memory.c kernel/exception.c kernel/hash.c kernel/debug.c kernel/backtrace.c kernel/object.c kernel/array.c kernel/extended/array.c kernel/string.c kernel/fcall.c kernel/require.c kernel/file.c kernel/operators.c kernel/concat.c kernel/variables.c kernel/filter.c kernel/iterator.c kernel/exit.c phal/entity.zep.c
	phal/format/abstractreader.zep.c
	phal/format/abstractwriter.zep.c
	phal/format/reader/abstractjsonreader.zep.c
	phal/format/reader/hal/jsonreader.zep.c
	phal/format/readerinterface.zep.c
	phal/format/writer/abstractjsonwriter.zep.c
	phal/format/writer/hal/jsonwriter.zep.c
	phal/format/writerinterface.zep.c
	phal/link.zep.c
	phal/linkinterface.zep.c "
	PHP_NEW_EXTENSION(phal, $phal_sources, $ext_shared)

	old_CPPFLAGS=$CPPFLAGS
	CPPFLAGS="$CPPFLAGS $INCLUDES"

	AC_CHECK_DECL(
		[HAVE_BUNDLED_PCRE],
		[
			AC_CHECK_HEADERS(
				[ext/pcre/php_pcre.h],
				[
					PHP_ADD_EXTENSION_DEP([phal], [pcre])
					AC_DEFINE([ZEPHIR_USE_PHP_PCRE], [1], [Whether PHP pcre extension is present at compile time])
				],
				,
				[[#include "main/php.h"]]
			)
		],
		,
		[[#include "php_config.h"]]
	)

	AC_CHECK_DECL(
		[HAVE_JSON],
		[
			AC_CHECK_HEADERS(
				[ext/json/php_json.h],
				[
					PHP_ADD_EXTENSION_DEP([phal], [json])
					AC_DEFINE([ZEPHIR_USE_PHP_JSON], [1], [Whether PHP json extension is present at compile time])
				],
				,
				[[#include "main/php.h"]]
			)
		],
		,
		[[#include "php_config.h"]]
	)

	CPPFLAGS=$old_CPPFLAGS
fi
