# Maintainer: Sven-Hendrik Haase <sh@lutzhaase.com>
# Contributor: Malte Rabenseifner <malte@zearan.de>
# Contributor: John Gerritse <reaphsharc@gmail.com>

pkgname=lsb-release
pkgver=1.4
pkgrel=16
pkgdesc="LSB version query program"
arch=('any')
url="http://www.linuxbase.org/"
license=('GPL2')
depends=('bash')
install=lsb-release.install
source=(https://downloads.sourceforge.net/lsb/$pkgname-$pkgver.tar.gz
        lsb_release_description.patch)
sha512sums=('84f6f8794380463587005043f601b7a40190cd9e3409abff7f5ce7658cf029a14346eff87838296d90307192bdeff68cc00480c5c04814da7acdb3e220640fde'
            '145ef64f90f5e6cc59075679e640cf7c1ad02617c12eff17f10b05c1cc219591fdba1b27be2b2c8480742aed24ce81d6a7badcbaca6772faea4ebc6a55695b62')

build() {
  cd "$srcdir/$pkgname-$pkgver"

  patch -Np0 < "$srcdir/lsb_release_description.patch"

  make
}

package() {
  cd "$srcdir/$pkgname-$pkgver"

  install -dm755 "$pkgdir/etc"
  echo "LSB_VERSION=$pkgver" >> "$pkgdir/etc/lsb-release"
  echo "DISTRIB_ID=Arch" >> "$pkgdir/etc/lsb-release"
  echo "DISTRIB_RELEASE=rolling" >> "$pkgdir/etc/lsb-release"
  echo "DISTRIB_DESCRIPTION=\"Arch Linux\"" >> "$pkgdir/etc/lsb-release"

  install -Dm 644 lsb_release.1.gz "$pkgdir/usr/share/man/man1/lsb_release.1.gz"
  install -Dm 755 lsb_release "$pkgdir/usr/bin/lsb_release"
}
