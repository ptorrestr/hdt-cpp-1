FROM python:3.6-alpine3.10

RUN apk update\
	&& apk add --no-cache\
		build-base curl\
		automake autoconf\
		pkgconfig	libtool\
		zlib-dev git

ENV SERD_NAME "serd"
ENV SERD_VERSION "0.28.0"
ENV SERD_BASE_URL "https://github.com/drobilla/$SERD_NAME/archive"
ENV SERD_EXT "tar.gz"
ENV SERD_URL "$SERD_BASE_URL/v$SERD_VERSION.$SERD_EXT"
ENV SERD_BUILD_FOLDER "/build/serd"
RUN curl -L $SERD_URL -o "$SERD_NAME-$SERD_VERSION.$SERD_EXT"\
	&& mkdir -p $SERD_BUILD_FOLDER\
	&& tar xf "$SERD_NAME-$SERD_VERSION.$SERD_EXT" -C $SERD_BUILD_FOLDER --strip-components=1\
	&& cd $SERD_BUILD_FOLDER\
	&& ./waf configure\
	&& ./waf\
	&& ./waf install\
	&& rm -rf $SERD_BUILD_FOLDER

ENV HDT_GIT "https://github.com/rdfhdt/hdt-cpp.git"
ENV HDT_BUILD_FOLDER "/build/hdt"
RUN git clone $HDT_GIT $HDT_BUILD_FOLDER\
	&& cd $HDT_BUILD_FOLDER\
		&& bash ./autogen.sh\
		&& ./configure\
		&& make -j$(nproc)\
		&& make install\
		&& rm -rf $HDT_BUILD_FOLDER
