# Maintainer: Johannes Löthberg <johannes@kyriasis.com>
# Contributor: George Rawlinson <grawlinson@archlinux.org>
# Contributor: Timothy Redaelli <timothy.redaelli@gmail.com>
# Contributor: Vianney le Clément <vleclement AT gmail·com>
# Contributor: Peter Simons <simons@cryp.to>

pkgbase=parallel
pkgname=('parallel' 'parallel-docs')
pkgver=20211222
pkgrel=1
pkgdesc='A shell tool for executing jobs in parallel'
arch=('any')
url='https://www.gnu.org/software/parallel/'
license=('GPL3')
source=(https://ftp.gnu.org/gnu/$pkgname/$pkgname-$pkgver.tar.bz2{,.sig}
        0001-Remove-citation-things.patch
        0002-Remove-GNU-branding.patch)
sha512sums=('864d9e9ab690008d0900544c409cef28758ff24a74ca4909ad7ada877ad7fd308995a929f626618ad6779daeaf44d13dda6c7aae274bbf66b8053d6d10ea809a'
            'SKIP'
            '0857bb0639fc79a81bd9bc2a35008f80898f3314d26f0138195aeee54f3ff14ef257db32c8b322ac93ed5bd52b2196ce636550c08b57ab9ac1a0c191f09550fd'
            '304fc64ce5b5b664bdd1480da54863c061940f5f6255d13462f3bec5ff742636f34769650c64875dc7dda7c552b7ba6ee63f8fea1aa914f6d2210f2d49a2ba7b')
b2sums=('f2258632ab4a8f0a13dcf7e617155a30eda32f792d2dcda3d31a0e0515d06546df42abd369e17badfd1ab5ec5099d390ee42bd70fbd603c98a974db142940b32'
        'SKIP'
        '1b32ab5d4dc3999197eda525e8a46aca1d5fba5a8ebbf639b6d977d98bd00f2abe0533f4b0fee3aedc9eca31907ff61ca99ffff496099a0be0589aa6ad3deb5c'
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

package_parallel() {
  depends=('perl' 'procps')

  cd parallel-$pkgver
  make DESTDIR="$pkgdir" install
  mv "$pkgdir/usr/share/doc" docs
}

package_parallel-docs() {
  pkgdesc+=' (documentation)'

  cd parallel-$pkgver

  install -vd "$pkgdir/usr/share/doc"
  mv -v docs/* "$pkgdir/usr/share/doc"
}

# vim:set ts=2 sw=2 et:
