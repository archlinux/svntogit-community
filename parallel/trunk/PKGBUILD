# Maintainer: Johannes Löthberg <johannes@kyriasis.com>
# Contributor: George Rawlinson <grawlinson@archlinux.org>
# Contributor: Timothy Redaelli <timothy.redaelli@gmail.com>
# Contributor: Vianney le Clément <vleclement AT gmail·com>
# Contributor: Peter Simons <simons@cryp.to>

pkgname=parallel
pkgver=20211122
pkgrel=1
pkgdesc='A shell tool for executing jobs in parallel'
arch=('any')
url='https://www.gnu.org/software/parallel/'
license=('GPL3')
depends=('perl' 'procps')
source=(https://ftp.gnu.org/gnu/$pkgname/$pkgname-$pkgver.tar.bz2{,.sig}
        0001-Remove-citation-things.patch
        0002-Remove-GNU-branding.patch)
sha512sums=('3cadf5be292e28c7a24653ed7d712a087d98cf7332a677a7f10c5abb260d82b8e5cbd9c61f25c77b1b08427716bd47a3483e6c1e188a594c0ef2e881aa055e83'
            'SKIP'
            '0450c81cf68d6d42814418e012f8cf64f515e1c89c2b2e833ee0e660518af76fd7046fd8aaf7dd04d0272a9c766930a63a3388e3cdbd7ea8030da0d780af27e0'
            '304fc64ce5b5b664bdd1480da54863c061940f5f6255d13462f3bec5ff742636f34769650c64875dc7dda7c552b7ba6ee63f8fea1aa914f6d2210f2d49a2ba7b')
b2sums=('55a9243f8781a781b75d51d0d6864ae2ccd5ef80d3da5227272826b400ec9e05dc62cbfbca09cd2e342d286b4eac3f99ec6c647c285e606cc903ab05808636a9'
        'SKIP'
        'a4bfe7d7e7a0c9fa30e10b291e08f31c807ef99dfa9f5054d6e9a4ddf9edcb2f9a33a4af3b6080f53be1d4fe559e4204692bb833c2aa83d69bb03409db7d5e71'
        '684576067936f30e24a00c0283b961f56451eb8924a26c6f426a23521b1e272890772e51d817de7386ebf6863c5f8ba9c5598d17d56f3df1875f4b36bcee13d3')
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
