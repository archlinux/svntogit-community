# Maintainer: BlackIkeEagle <ike DOT devolder AT gmail DOT com>
# Contributor: Sergej Pupykin <pupykin.s+arch@gmail.com>
# Contributor: Jens Adam <jra@byte.cx>

pkgname=fpc-src
pkgver=3.2.0
pkgrel=1
pkgdesc='Sources for the FreePascal compiler (required by the Lazarus IDE)'
url='https://www.freepascal.org/'
license=('GPL')
arch=('any')
options=('!strip' 'staticlibs')
source=("ftp://ftp.freepascal.org/pub/fpc/dist/$pkgver/source/fpcbuild-$pkgver.tar.gz")
sha512sums=('a584f0bc908b380cb3da6bc624ba5de7de803a79dfec33c03f10b468939d4f0d5d7d9ad85ce65e49babd7437e8dba920cb62ac694a4449fc9151ef8ce8e68252')

package() {
  cd "$srcdir"/fpcbuild-$pkgver/fpcsrc
  mkdir -p "$pkgdir"/usr/lib/fpc/src
  cp -R . "$pkgdir"/usr/lib/fpc/src
}
