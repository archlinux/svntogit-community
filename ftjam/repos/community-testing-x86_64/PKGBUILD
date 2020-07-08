# Maintainer: Bruno Pagani <archange@archlinux.org>
# Contributor: Roman Kyrylych <roman@gmail.com>

pkgname=ftjam
pkgver=2.5.3rc2
pkgrel=6
pkgdesc="FT Jam - an enhanced version of the Jam build tool"
arch=('x86_64')
url="https://freetype.org/jam/"
license=('custom')
depends=('glibc')
provides=('jam')
#source=("https://downloads.sourceforge.net/freetype/${pkgname}-${pkgver}.tar.bz2"
source=("http://david.freetype.org/jam/${pkgname}-${pkgver}.tar.bz2"
        'license.txt')
md5sums=('911cc4191b3e7213905d107962b4529b'
         'ef8ff7da77fe60e25d1e3e740600f1f0')
sha256sums=('a9f8a274049893a4d1f1ad82f7b04f3ebc2554635dd606185e20ba97cb4d64ec'
            '78a6448f2e349e807741fa0abec0724bd35fd63cde0a4f6a46fee4b3ce4568fa')

build() {
  cd ${pkgname}-${pkgver}
  ./configure --prefix=/usr
  make
}

package() {
  cd ${pkgname}-${pkgver}
  make DESTDIR="${pkgdir}" install
  install -Dm644 ../license.txt -t "${pkgdir}"/usr/share/licenses/${pkgname}/
}
