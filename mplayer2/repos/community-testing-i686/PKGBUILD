# $Id$
# Maintainer: Stéphane Gaudreault <stephane@archlinux.org>
# Contributor: Bartek Piotrowski <barthalion@gmail.com>

pkgname=mplayer2
pkgver=2.0
pkgrel=7
pkgdesc="A movie player"
arch=('i686' 'x86_64')
license=('GPL')
url="http://www.mplayer2.org/"
depends=('ffmpeg' 'libass' 'libxxf86dga' 'libxxf86vm' 'libmad' 'cdparanoia' 'libxinerama' 'sdl' 'libtheora' 'xvidcore' 'libmng' 'libxss'
         'libgl' 'aalib' 'jack' 'libcaca' 'x264' 'faac' 'lirc-utils' 'ttf-dejavu' 'libxvmc' 'enca' 'libvdpau'
         'opencore-amr' 'libdca' 'a52dec' 'schroedinger' 'libvpx' 'libpulse' 'ncurses' 'freetype2' 'libdvdcss' 'libdvdread' 'libdvdnav')
makedepends=('live-media' 'mesa' 'unzip' 'yasm')
backup=('etc/mplayer/codecs.conf' 'etc/mplayer/input.conf')
replaces=('mplayer')
provides=('mplayer')
conflicts=('mplayer')
source=(http://ftp.mplayer2.org/pub/release/${pkgname}-build-${pkgver/_/-}.tar.xz)
md5sums=('05b93784de995235e2758f182de15f73')
options=('!emptydirs')

build() {
    # Custom CFLAGS break the mplayer build
    unset CFLAGS LDFLAGS

    cd "${srcdir}/${pkgname}-build-${pkgver}"

    # Use system ffmpeg
    sed -i -e '/^mplayer: /s/ffmpeg//' Makefile
    rm -r ffmpeg-mt

    cd ${pkgname/2/}

    ./configure --prefix=/usr \
                --enable-runtime-cpudetection \
                --disable-gui \
                --disable-arts \
                --disable-fribidi \
                --disable-speex \
                --disable-openal \
                --disable-libdv \
                --disable-musepack \
                --disable-esd \
                --disable-mga \
                --enable-xvmc \
                --language=all \
                --confdir=/etc/mplayer
    make
}

package() {
    cd "${srcdir}/${pkgname}-build-${pkgver}/${pkgname/2/}"

    make DESTDIR="${pkgdir}" install
    install -Dm644 etc/{codecs.conf,input.conf,example.conf} "${pkgdir}"/etc/mplayer/
    install -dm755 "${pkgdir}"/usr/share/mplayer/
    ln -s /usr/share/fonts/TTF/DejaVuSans.ttf "${pkgdir}"/usr/share/mplayer/subfont.ttf
}
