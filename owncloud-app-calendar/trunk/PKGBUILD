# $Id: PKGBUILD 103944 2014-01-13 20:31:53Z spupykin $
# Maintainer: Sergej Pupykin <pupykin.s+arch@gmail.com>

pkgname=owncloud-app-calendar
pkgver=8.0.0
pkgrel=1
pkgdesc="Calendar app for owncloud"
arch=('any')
url="http://owncloud.org/"
license=('GPL')
depends=('owncloud')
makedepends=()
options=('!strip')
source=("$pkgname-$pkgver.tar.gz::https://github.com/owncloud/calendar/archive/v$pkgver.tar.gz")
md5sums=('199eb5662d1938d2365cc45faef7c3da')

package() {
  install -d ${pkgdir}/usr/share/webapps/owncloud/apps
  cp -a ${srcdir}/calendar-$pkgver ${pkgdir}/usr/share/webapps/owncloud/apps/calendar
}
