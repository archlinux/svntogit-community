# $Id: PKGBUILD 103944 2014-01-13 20:31:53Z spupykin $
# Maintainer: Sergej Pupykin <pupykin.s+arch@gmail.com>

pkgname=owncloud-app-bookmarks
pkgver=8.0.0
pkgrel=1
pkgdesc="Bookmarks app for owncloud"
arch=('any')
url="http://owncloud.org/"
license=('GPL')
depends=('owncloud')
makedepends=()
options=('!strip')
source=("$pkgname-$pkgver.tar.gz::https://github.com/owncloud/bookmarks/archive/v$pkgver.tar.gz")
md5sums=('ff7e853d5a22714e09e643c083b4529c')

package() {
  install -d ${pkgdir}/usr/share/webapps/owncloud/apps
  cp -a ${srcdir}/bookmarks-$pkgver ${pkgdir}/usr/share/webapps/owncloud/apps/bookmarks
}
