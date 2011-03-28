# $Id$
# Maintainer: Stéphane Gaudreault <stephane@archlinux.org>
# Contributor: Bartek Piotrowski <barthalion@gmail.com>

pkgname=mplayer2
pkgver=2.0
pkgrel=3
pkgdesc="A movie player"
arch=('i686' 'x86_64')
license=('GPL')
url="http://www.mplayer2.org/"
depends=('ffmpeg' 'gettext' 'libass' 'libcss' 'libgl' 'libxvmc' 'libxss' 'libxxf86dga' 'libxxf86vm' 'sdl' 'ttf-dejavu' 'libvdpau')
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

    cd "${srcdir}/${pkgname}-build-${pkgver}/${pkgname/2/}"

    ./configure --prefix=/usr \
                --enable-runtime-cpudetection \
                --disable-arts \
                --disable-speex \
                --disable-openal \
                --disable-libdv \
                --disable-musepack \
                --disable-esd \
                --disable-mga \
                --disable-fribidi \
                --enable-xvmc \
                --enable-translation \
                --language-doc=all \
                --language-man=all \
                --language-msg=all \
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
