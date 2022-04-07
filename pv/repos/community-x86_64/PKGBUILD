# Maintainer: Lukas Fleischer <lfleischer@archlinux.org>
# Maintainer: Caleb Maclennan <caleb@alerque.com>
# Contributor: Kaiting Chen <kaitocracy@gmail.com>
# Contributor: Aaron Schaefer <aaron@elasticdog.com>

pkgname=pv
pkgver=1.6.20
pkgrel=2
pkgdesc='A terminal-based tool for monitoring the progress of data through a pipeline.'
arch=('x86_64')
url='http://www.ivarch.com/programs/pv.shtml'
_url="https://github.com/a-j-wood/$pkgname"
license=('custom:Artistic 2.0')
depends=('glibc')
# source=("http://www.ivarch.com/programs/sources/$pkgname-$pkgver.tar.bz2")
source=("$_url/releases/download/v$pkgver/$pkgname-$pkgver.tar.bz2")
md5sums=('85b25c827add82ebdd5a58a5ffde1d7d')
sha256sums=('e831951eff0718fba9b1ef286128773b9d0e723e1fbfae88d5a3188814fdc603')
b2sums=('b50623f623231e8e8615f960bad83d10e12d5274c57d23ea843d16fce30b3e690284b2d9b01f82a16b9790e2bf26f80f560e226589a62ca677a2cf90ea007691')

build() {
  cd "${srcdir}/${pkgname}-${pkgver}"

  ./configure --prefix=/usr --mandir=/usr/share/man
  make
}

package() {
  cd "${srcdir}/${pkgname}-${pkgver}"

  make DESTDIR="$pkgdir" install
  install -Dm0644 doc/COPYING "$pkgdir/usr/share/licenses/$pkgname/COPYING"
}
