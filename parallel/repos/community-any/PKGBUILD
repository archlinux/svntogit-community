# Maintainer: Johannes Löthberg <johannes@kyriasis.com>
# Maintainer: George Rawlinson <grawlinson@archlinux.org>
# Contributor: Timothy Redaelli <timothy.redaelli@gmail.com>
# Contributor: Vianney le Clément <vleclement AT gmail·com>
# Contributor: Peter Simons <simons@cryp.to>

pkgbase=parallel
pkgname=('parallel' 'parallel-docs')
pkgver=20221222
pkgrel=1
pkgdesc='A shell tool for executing jobs in parallel'
arch=('any')
url='https://www.gnu.org/software/parallel/'
license=('GPL3')
source=(
  "https://ftp.gnu.org/gnu/$pkgbase/$pkgbase-$pkgver.tar.bz2"{,.sig}
  '0001-Remove-citation-things.patch'
)
sha512sums=('f5e67863a3287ef8836c65f53bc8759d47a17cb457d3a42fe7ffcdc3acda3b46224ce06a40d7ec46339768d95b7d06d5cdc790ad0f8a615fedc5416e14b7301f'
            'SKIP'
            'ccabe0f7c618b4fe97ca1c8081847533a4f09a56d913245db95e353ee66cd4cc63ce30eb608343f77b34823a2f7e039b184feb07845c1da83b3f8eec24897171')
b2sums=('cfbbe104be248ff1d96495e821161eb76aabedb3cb002d002d6f92dba6130790f767918de7da8249ded694002d1a572f384656bccbb59e0c7f834d874721d79e'
        'SKIP'
        '3a0c5b570fc2544966588c0434d6d772410c5072242114c4afad9b65773700b3b35c913761537bdaea4047a4c753e85ebe34b368c715d554c706224cf5a95065')
validpgpkeys=('CDA01A4208C4F74506107E7BD1AB451688888888')

prepare() {
  cd "$pkgbase-$pkgver"

  # remove citation warnings
  patch -p1 <"$srcdir"/0001-Remove-citation-things.patch

  # remove gnu branding
  sed \
    --in-place \
    --regexp-extended \
    --expression 's/GNU\s{1,3}Parallel/Parallel/g' \
    --expression 's/run_gnu_parallel/run_parallel/g' \
    --expression 's/with_GNU_Parallel/with_Parallel/g' \
    --expression 's/GNU \$Global::progname/\$Global::progname/g' \
    --expression 's/@GNU_Parallel/@Parallel/g' \
    src/parallel
}

build() {
  cd "$pkgbase-$pkgver"

  ./configure --prefix=/usr

  make
}

package_parallel() {
  depends=('perl' 'procps')

  cd "$pkgbase-$pkgver"

  make DESTDIR="$pkgdir" install

  # split documentation out of main package
  mv "$pkgdir/usr/share/doc" docs
}

package_parallel-docs() {
  pkgdesc+=' (documentation)'

  cd "$pkgbase-$pkgver"

  install -vd "$pkgdir/usr/share/doc"
  mv -v docs/* "$pkgdir/usr/share/doc"
}

# vim:set ts=2 sw=2 et:
