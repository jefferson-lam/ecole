find_or_download_package(
	NAME xtl
	URL https://github.com/xtensor-stack/xtl/archive/0.7.2.tar.gz
	URL_HASH SHA256=95c221bdc6eaba592878090916383e5b9390a076828552256693d5d97f78357c
	CONFIGURE_ARGS -D BUILD_TESTS=OFF
)

find_or_download_package(
	NAME xsimd
	URL https://github.com/xtensor-stack/xsimd/archive/7.4.9.tar.gz
	URL_HASH SHA256=f6601ffb002864ec0dc6013efd9f7a72d756418857c2d893be0644a2f041874e
	CONFIGURE_ARGS -D BUILD_TESTS=OFF
)

find_or_download_package(
	NAME xtensor
	URL https://github.com/xtensor-stack/xtensor/archive/0.23.1.tar.gz
	URL_HASH SHA256=b9bceea49db240ab64eede3776d0103bb0503d9d1f3ce5b90b0f06a0d8ac5f08
	CONFIGURE_ARGS -D BUILD_TESTS=OFF
)

find_or_download_package(
	NAME span-lite
	URL https://github.com/martinmoene/span-lite/archive/v0.9.0.tar.gz
	URL_HASH SHA256=cdb5f86e5f5e679d63700a56de734c44fe22a574a17347d09dbaaef80619af91
	CONFIGURE_ARGS
		-D SPAN_LITE_OPT_BUILD_TESTS=OFF
		-D SPAN_LITE_OPT_BUILD_EXAMPLES=OFF
)

find_or_download_package(
	NAME range-v3
	URL https://github.com/ericniebler/range-v3/archive/0.11.0.tar.gz
	URL_HASH SHA256=376376615dbba43d3bef75aa590931431ecb49eb36d07bb726a19f680c75e20c
	CONFIGURE_ARGS
		-D RANGE_V3_TESTS=OFF
		-D RANGE_V3_EXAMPLES=OFF
		-D RANGE_V3_PERF=OFF
		-D RANGE_V3_DOCS=OFF
)

find_or_download_package(
	NAME fmt
	URL https://github.com/fmtlib/fmt/archive/8.0.1.tar.gz
	URL_HASH SHA256=b06ca3130158c625848f3fb7418f235155a4d389b2abc3a6245fb01cb0eb1e01
	CONFIGURE_ARGS
		-D FMT_TEST=OFF
		-D FMT_DOC=OFF
		-D FMT_INSTALL=ON
		-D CMAKE_BUILD_TYPE=Release
		-D BUILD_SHARED_LIBS=OFF
		-D CMAKE_POSITION_INDEPENDENT_CODE=${CMAKE_POSITION_INDEPENDENT_CODE}
)

find_or_download_package(
	NAME robin_hood
	URL https://github.com/martinus/robin-hood-hashing/archive/refs/tags/3.11.2.tar.gz
	URL_HASH SHA256=148b4fbd4fbb30ba10cc97143dcbe385078801b9c9e329cd477c1ea27477cb73
	CONFIGURE_ARGS -D RH_STANDALONE_PROJECT=OFF
)
