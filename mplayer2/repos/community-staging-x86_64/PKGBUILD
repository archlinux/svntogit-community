# $Id$
# Maintainer: Stéphane Gaudreault <stephane@archlinux.org>
# Contributor: Bartek Piotrowski <barthalion@gmail.com>

pkgname=mplayer2
pkgver=2.0.20111101
pkgrel=1
pkgdesc="A movie player"
arch=('i686' 'x86_64')
license=('GPL')
url="http://www.mplayer2.org/"
depends=('libgl' 'libvdpau' 'ffmpeg' 'libdvdcss' 'libdvdread' 'libdvdnav' 'libxvmc' 'libass' 'fontconfig' 'freetype2'
         'ttf-dejavu' 'sdl' 'aalib' 'libcaca' 'faad2' 'libpulse' 'jack' 'ncurses' 'libxxf86vm' 'cdparanoia' 'libmad'
         'a52dec' 'libdca' 'libxxf86dga' 'libxss' 'mpg123' 'ladspa')
makedepends=('live-media' 'mesa' 'unzip' 'yasm' 'git')
backup=('etc/mplayer/codecs.conf' 'etc/mplayer/input.conf')
provides=('mplayer')
conflicts=('mplayer')
#source=(http://ftp.mplayer2.org/pub/release/${pkgname}-${pkgver/_/-}.tar.xz
source=(ftp://ftp.archlinux.org/other/community/${pkgname}/${pkgname}-${pkgver}.tar.xz)
sha1sums=('78c78605733ca792bb12a52a751a508bfc0f213d')
options=('!emptydirs')

# source PKGBUILD && mksource
mksource() {
  _gitroot="git://git.mplayer2.org/mplayer2.git"
  _gitname="${pkgname}-${pkgver}"

  if [[ -d "$_gitname" ]]; then
    cd "$_gitname" && git pull origin
  else
    git clone "$_gitroot" "$_gitname"
  fi

  tar -cJvf ${_gitname}.tar.xz ${_gitname}
  rm -fr ${_gitname}
}

build() {
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

    install -dm755 "${pkgdir}"/usr/share/applications/
    install -m 644 etc/mplayer.desktop "${pkgdir}"/usr/share/applications/
}
