# Maintainer: Sven-Hendrik Haase <sh@lutzhaase.com>
# Contributor: t3ddy  <t3ddy1988 "at" gmail {dot} com>
# Contributor: Adrián Chaves Fernández (Gallaecio) <adriyetichaves@gmail.com>
pkgname=0ad-data
_pkgname=0ad
pkgver=a26
_pkgver=0.0.26-alpha
pkgrel=1
pkgdesc="Cross-platform, 3D and historically-based real-time strategy game (data files)"
arch=('any')
url="http://play0ad.com/"
license=('GPL2' 'CCPL')
source=("https://releases.wildfiregames.com/0ad-${_pkgver}-unix-data.tar.xz")
sha512sums=('8fe29fce68737d5b7001c8c2a7198766583b22556129cd2d927823da9b2c58f224fb1207f35bd03abea9380cf24d00ab6257b0dba86ce3ad1f357d7006f051d6')

package() {
  cd "$_pkgname-$_pkgver"

  install -d "${pkgdir}/usr/share/${_pkgname}/data"
  cp -r "binaries/data" "${pkgdir}/usr/share/${_pkgname}"
}
