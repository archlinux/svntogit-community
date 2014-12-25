# Maintainer: Maxwell Pray a.k.a. Synthead <synthead@gmail.com>
# Contributor: Justin Davis <jrcd83@gmail.com>

pkgname="perl-variable-magic"
_cpanname="Variable-Magic"
pkgver="0.54"
pkgrel="1"
pkgdesc="Associate user-defined magic to variables from Perl."
arch=("i686" "x86_64")
license=("PerlArtistic" "GPL")
options=("!emptydirs")
depends=("perl>=5.5.0")
url="http://search.cpan.org/dist/$_cpanname"
source=("http://search.cpan.org/CPAN/authors/id/V/VP/VPIT/$_cpanname-$pkgver.tar.gz")
sha1sums=('3f254afd1923f42585dd7c30fcc283165f2f178a')

# Function to change to the working directory and set
# environment variables to override undesired options.
prepareEnvironment() {
  cd "$srcdir/$_cpanname-$pkgver"
  export \
    PERL_MM_USE_DEFAULT="1" \
    PERL_AUTOINSTALL="--skipdeps" \
    PERL_MM_OPT="INSTALLDIRS=vendor DESTDIR='${pkgdir//\'/\\\'}'" \
    PERL_MB_OPT="--installdirs vendor --destdir '${pkgdir//\'/\\\'}'" \
    MODULEBUILDRC="/dev/null"
}

build() {
  prepareEnvironment
  /usr/bin/perl Makefile.PL
  make
}

check() {
  prepareEnvironment
  make test
}

package() {
  prepareEnvironment
  make install

  # Remove "perllocal.pod" and ".packlist".
  find "$pkgdir" -name .packlist -o -name perllocal.pod -delete
}
