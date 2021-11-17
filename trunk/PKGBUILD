# Maintainer: Johannes Löthberg <johannes@kyriasis.com>
# Contributor: George Rawlinson <grawlinson@archlinux.org>
# Contributor: Timothy Redaelli <timothy.redaelli@gmail.com>
# Contributor: Vianney le Clément <vleclement AT gmail·com>
# Contributor: Peter Simons <simons@cryp.to>

pkgname=parallel
pkgver=20211022
pkgrel=1
pkgdesc='A shell tool for executing jobs in parallel'
arch=('any')
url='https://www.gnu.org/software/parallel/'
license=('GPL3')
depends=('perl' 'procps')
source=(https://ftp.gnu.org/gnu/$pkgname/$pkgname-$pkgver.tar.bz2{,.sig}
        0001-Remove-citation-things.patch
        0002-Remove-GNU-branding.patch)
sha512sums=('bf48f7b13ecfae7275efa5935fcbfbbc942c290daa226243c12de15f3a4579ce64c862b8bae93e5c97af798fb529d4cd750e6b83803f48c33604e3a3212fe157'
            'SKIP'
            'fa594beb8cf8298c52f10251263cd23109cb125fc4dafd84d1d366cbf923f2d460438dbf20250712cfa4249d0e7fe18941b531fb16e0a6fc41acee8b77bf4fad'
            '211f6f65d1b1ad6a7fad827ddc0cb1a83d43b5fa8c542337a1fed4e550a3bf0e4941f37ef7d12943b15f789f616f9aa14a959da09af783466475a19ef84720d7')
b2sums=('3d50e5fd078b69c7d9b0f2c27d3c853d7b731ed5a04ff74a763691e36e89bbc10b79a95ad6c96bfe760a6fc56ca3b4d86dc1a4d2315c17c1cbb307bc2300e95d'
        'SKIP'
        '147cf080306bf978ac625dddb717c83c14f6dfdc2f61b429e1f4cd239b477d30a9f8e630722f0226d035e6a053dd797a0c9b5898dd9440bd9aa3b2d0689d8927'
        'd3c6e1546b5d806d5c0762a697fb1bf72b642472c7960a70d818e1803e7f7ca00561ef2e87a9614ec6bafce05172fe1f67b38cb009113f9280f4a658b5b1e1d8')
validpgpkeys=('CDA01A4208C4F74506107E7BD1AB451688888888')

prepare() {
  cd parallel-$pkgver
  patch -p1 <"$srcdir"/0001-Remove-citation-things.patch
  patch -p1 <"$srcdir"/0002-Remove-GNU-branding.patch
}

build() {
  cd parallel-$pkgver
  ./configure --prefix=/usr
  make
}

package() {
  cd parallel-$pkgver
  make DESTDIR="$pkgdir/" install
}

# vim:set ts=2 sw=2 et:
