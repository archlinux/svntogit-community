# $Id$
# Maintainer: Stéphane Gaudreault <stephane@archlinux.org>
# Contributor: Bartek Piotrowski <barthalion@gmail.com>

pkgname=mplayer2
pkgver=2.0
pkgrel=11
pkgdesc="A movie player"
arch=('i686' 'x86_64')
license=('GPL')
url="http://www.mplayer2.org/"
depends=('libgl' 'libvdpau' 'ffmpeg' 'libdvdcss' 'libdvdread' 'libdvdnav' 'libxvmc' 'libass' 'fontconfig' 'freetype2' 'ttf-dejavu'
         'sdl' 'aalib' 'libcaca' 'faad2' 'libpulse' 'jack' 'ncurses' 'libxxf86vm' 'cdparanoia' 'libmad' 'a52dec' 'libdca' 'libxxf86dga')
makedepends=('live-media' 'mesa' 'unzip' 'yasm')
backup=('etc/mplayer/codecs.conf' 'etc/mplayer/input.conf')
provides=('mplayer')
conflicts=('mplayer')
source=(http://ftp.mplayer2.org/pub/release/${pkgname}-${pkgver/_/-}.tar.xz)
sha1sums=('0df8d4e5484128b7b28029273b7704ab5d5419bc')
options=('!emptydirs')

build() {
    # Custom CFLAGS break the mplayer build
    unset CFLAGS LDFLAGS

    cd "${srcdir}/${pkgname}-${pkgver}"

    ./configure --prefix=/usr \
                --enable-runtime-cpudetection \
                --disable-arts \
                --disable-speex \
                --disable-openal \
                --disable-libdv \
                --disable-musepack \
                --disable-esd \
                --disable-mga \
                --enable-xvmc \
                --language=all \
                --enable-translation \
                --confdir=/etc/mplayer
    make
}

package() {
    cd "${srcdir}/${pkgname}-${pkgver}"

    make DESTDIR="${pkgdir}" install
    install -Dm644 etc/{codecs.conf,input.conf,example.conf} "${pkgdir}"/etc/mplayer/
    install -dm755 "${pkgdir}"/usr/share/mplayer/
    ln -s /usr/share/fonts/TTF/DejaVuSans.ttf "${pkgdir}"/usr/share/mplayer/subfont.ttf
}
